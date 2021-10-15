#include <ros.h>
#include <geometry_msgs/Twist.h>
#include <math.h>
#include <std_msgs/String.h>
#include <SoftwareSerial.h>



#include <std_msgs/UInt16.h>

#include <Sabertooth.h>

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>



SoftwareSerial SWSerial(NOT_A_PIN, 18); // RX on no pin (unused), TX on pin 11 (to S1).

SoftwareSerial portROS(0, 1);
Sabertooth rightBack(128);
Sabertooth rightFront(129);
Sabertooth leftBack(130);
Sabertooth leftFront(131);
Adafruit_BNO055 bno = Adafruit_BNO055(55);




const long CONTROL_TIMEOUT = 1000; //ms to wait  before killing motors


void cmdVelCallback(const geometry_msgs::Twist&);
ros::NodeHandle nh;
ros::Subscriber<geometry_msgs::Twist> subscriber("cmd_vel", &cmdVelCallback);



geometry_msgs::Twist msg;
ros::Publisher chatter_pub("cmd_vel", &msg);

std_msgs::String str_msg;

ros::Publisher sensorData("sensorData",&str_msg);

ros::Publisher arduinoLog("arduinoLog",&str_msg);
ros::Publisher currentData("currentData",&str_msg);


unsigned long lastData = 0;



void cmdVelCallback(const geometry_msgs::Twist &twist)
{

  // this function is called as soon as there is any cmd_vel command in the ros network

  lastData = millis();

  // this variable is given forth/back velocity in range of [-0.5 +0.5]
  const float linear = twist.linear.x;
  // this variable is given left/right velocity in range of [-1 +1]
  const float spin = twist.angular.z;



  // give movement to forth/back direction
  forward(int(66*linear));


  // if given command is right means spin is negative
  if (spin<0)
  {
    turn(int(-100*spin),10);
  }
  else if (spin>0)
  {
    turn(int(100*spin),10);
  }

}


void setup() {



  SWSerial.begin(9600);
  portROS.begin(57600);

  nh.initNode();
  nh.subscribe(subscriber);
  nh.advertise(chatter_pub);

  nh.advertise(sensorData);
  nh.advertise(arduinoLog);
  nh.advertise(currentData);

  int sensor_check = 0;
 while((!bno.begin())||sensor_check<10)
  {
    /* There was a problem detecting the BNO055 ... check your connections */

    nh.logerror("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    sensor_check++;
    delay(1000);
  }

  delay(1000);

  bno.setExtCrystalUse(true);

}

void loop()
{
  nh.spinOnce();

  if(millis() - lastData >= CONTROL_TIMEOUT)
  {
    lastData=millis();
    msg.linear.x = 0;
    msg.angular.z = 0;
    chatter_pub.publish(&msg);
  }
  String msg=("Current: "+ String(analogRead(A0),HEX)+' '+ String(analogRead(A1),HEX)+' '+ String(analogRead(A2),HEX)+' '
      +String(analogRead(A3),HEX));
    str_msg.data = msg.c_str();
      currentData.publish( &str_msg);


    publishSensorData();

}


// All own functions

void rightSpeed(int speed) {
  rightFront.motor(speed);
   rightBack.motor(speed);

  }

void leftSpeed(int speed) {
  leftBack.motor(speed);
   leftFront.motor(speed);
   }

int turn(int dauer, int geschw) { // left hand drive duration speed

  leftSpeed(geschw); //left speed (speed)
  rightSpeed(-geschw);
  delay(dauer);
  standgas();
}


int forward(int gas) { //forward
   rightFront.motor(gas);
   rightBack.motor(gas);
   leftBack.motor(gas);
   leftFront.motor(gas);
}



void standgas() {
   rightFront.motor(0);
   rightBack.motor(0);
   leftBack.motor(0);
   leftFront.motor(0);
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
