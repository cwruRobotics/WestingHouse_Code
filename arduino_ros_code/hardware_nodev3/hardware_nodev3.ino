
#include <ros.h>
#include <math.h>

#include <Wire.h>
#include <SoftwareSerial.h>

#include <Sabertooth.h>

#include <std_msgs/String.h>
#include <geometry_msgs/Twist.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>

// function predefs
void cmdVelCallback(const geometry_msgs::Twist&);
void stop();
void move(int, int);

// global hardware vars
SoftwareSerial portROS(0, 1);

Sabertooth back(128, Serial1);
Sabertooth front(129, Serial1);


Adafruit_BNO055 bno = Adafruit_BNO055(55);



// ros vars
ros::NodeHandle nh;

geometry_msgs::Twist msg;
std_msgs::String str_msg;
ros::Subscriber<geometry_msgs::Twist> vel_sub("cmd_vel", cmdVelCallback);

ros::Publisher chatter_pub("cmd_vel", &msg);
ros::Publisher sensorData("sensorData", &str_msg);
ros::Publisher arduinoLog("arduinoLog", &str_msg);
ros::Publisher currentData("currentData", &str_msg);

// global vars
const long TIMEOUT = 1000;
unsigned long last_time, dt;

int use_gyro = 1;

String debug_str;


void setup() {
 //Ros setup
  Serial1.begin(9600);
  portROS.begin(57600);

  nh.initNode();
  nh.subscribe(vel_sub);
  nh.loginfo("Setting up");

  nh.advertise(chatter_pub);
  nh.advertise(sensorData);
  nh.advertise(arduinoLog);
  nh.advertise(currentData);

  move(0, 0);

  //gyro setup
   int sensor_check = 0;
 while((!bno.begin())||sensor_check<10)
  {
    /* There was a problem detecting the BNO055 ... check your connections */

    nh.logerror("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    sensor_check++;
    delay(1000);
  }
  //if(sensor_check >= 10 ){
    //use_gyro = 0;
    //nh.logerror("Gyro not setup!!! Continueing with out");
  //}
  delay(1000);

  bno.setExtCrystalUse(true);
}

void loop() {
  // put your main code here, to run repeatedly:
  nh.spinOnce();

  dt = millis() - last_time;

  if(dt > 100) {
    move(0, 0);
  }
  String msg=("Current: "+ String(analogRead(A0),HEX)+' '+ String(analogRead(A1),HEX)+' '+ String(analogRead(A2),HEX)+' '
      +String(analogRead(A3),HEX));
    str_msg.data = msg.c_str();
      currentData.publish( &str_msg);
   if(use_gyro == 1){
    publishSensorData();
}


  Serial1.flush();


  delay(10);
}

char buf[128];


void cmdVelCallback(const geometry_msgs::Twist& twist) {
  last_time = millis();
  
  const float linear = twist.linear.x;
  const float spin = twist.angular.z;

  sprintf(buf, "Vals: %0.2f,%0.2f", linear, spin);
  nh.loginfo(buf);

  // TODO: Figure this out
  const int left = linear + spin;
  const int right = linear - spin;

  move(left, right);
  Serial1.flush();
}

void move(int left, int right) {
  sprintf(buf, "Setting Motors -- Left: %3d, Right: %3d", left, right);
  nh.loginfo(buf);
  front.motor(1, left);
  back.motor(1, left);

  front.motor(2, right);
  back.motor(2, right);
}

void stop() {
  move(0, 0);
}



void publishSensorData(){

//send sensor data packet
       String msg;
       //could add VECTOR_ACCELEROMETER, VECTOR_MAGNETOMETER,VECTOR_GRAVITY...
       sensors_event_t orientationData , angVelocityData , linearAccelData, magnetometerData, accelerometerData, gravityData;
       bno.getEvent(&orientationData, Adafruit_BNO055::VECTOR_EULER);
       bno.getEvent(&angVelocityData, Adafruit_BNO055::VECTOR_GYROSCOPE);
       bno.getEvent(&linearAccelData, Adafruit_BNO055::VECTOR_LINEARACCEL);
       bno.getEvent(&magnetometerData, Adafruit_BNO055::VECTOR_MAGNETOMETER);
       bno.getEvent(&accelerometerData, Adafruit_BNO055::VECTOR_ACCELEROMETER);
       bno.getEvent(&gravityData, Adafruit_BNO055::VECTOR_GRAVITY);

       msg += (printEvent(&orientationData));
       msg +=(printEvent(&angVelocityData));
       msg +=(printEvent(&linearAccelData));
       msg +=(printEvent(&magnetometerData));
       msg +=(printEvent(&accelerometerData));
       msg +=(printEvent(&gravityData));

      int8_t boardTemp = bno.getTemp();

      msg +=(F("temperature: "));
      msg +=(boardTemp);

      uint8_t system, gyro, accel, mag = 0;
      bno.getCalibration(&system, &gyro, &accel, &mag);

      msg +=("Calibration: Sys=");
      msg +=(String(system));
      msg +=(" Gyro=");
      msg +=(String(gyro,HEX));
      msg +=(" Accel=");
      msg +=(String(accel,HEX));
      msg +=(" Mag=");
      msg +=String(mag,HEX);

      msg += ("--");



      str_msg.data = msg.c_str();
      sensorData.publish( &str_msg);

}




// want to change to publish to diffrent topics
String printEvent(sensors_event_t* event) {

  String msg;
  double x = -1000000, y = -1000000 , z = -1000000; //dumb values, easy to spot problem
  if (event->type == SENSOR_TYPE_ACCELEROMETER) {
    msg += "Accl:" ;
    x = event->acceleration.x;
    y = event->acceleration.y;
    z = event->acceleration.z;
  }
  else if (event->type == SENSOR_TYPE_ORIENTATION) {
     msg += "Orient:";
    x = event->orientation.x;
    y = event->orientation.y;
    z = event->orientation.z;
  }
  else if (event->type == SENSOR_TYPE_MAGNETIC_FIELD) {
     msg += "Mag:";
    x = event->magnetic.x;
    y = event->magnetic.y;
    z = event->magnetic.z;
  }
  else if (event->type == SENSOR_TYPE_GYROSCOPE) {
     msg += "Gyro:";
    x = event->gyro.x;
    y = event->gyro.y;
    z = event->gyro.z;
  }
  else if (event->type == SENSOR_TYPE_ROTATION_VECTOR) {
     msg += "Rot:";
    x = event->gyro.x;
    y = event->gyro.y;
    z = event->gyro.z;
  }
  else if (event->type == SENSOR_TYPE_LINEAR_ACCELERATION) {
     msg += "Linear:";
    x = event->acceleration.x;
    y = event->acceleration.y;
    z = event->acceleration.z;
  }
  else if (event->type == SENSOR_TYPE_GRAVITY) {
     msg += "Gravity:";
    x = event->acceleration.x;
    y = event->acceleration.y;
    z = event->acceleration.z;
  }
  else {
    nh.logwarn("Unk:");
  }

   msg += "\tx= ";
   msg += x;
   msg += " |\ty= ";
   msg += y;
   msg += " |\tz= ";
   msg += z;

   return msg;
}
