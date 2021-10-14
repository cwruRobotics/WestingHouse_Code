

#include <ros.h>
#include <std_msgs/String.h>

#include <Sabertooth.h>
#include <SoftwareSerial.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>

SoftwareSerial SWSerial(NOT_A_PIN, 18); //tx1 no rx used
Sabertooth rightBack(128);
Sabertooth rightFront(129);
Sabertooth leftBack(130);
Sabertooth leftFront(131);
Adafruit_BNO055 bno = Adafruit_BNO055(55);

char terminator = '\n';
String command;

ros::NodeHandle nh;
std_msgs::String str_msg;

ros::Publisher sensorData("sensorData",&str_msg);

ros::Publisher arduinoLog("arduinoLog",&str_msg);




void moter_rb( const std_msgs::UInt16& cmd_msg){
  rightBack.motor(cmd_msg.data); //set servo angle, should be from -127 to 127  
   
  }
  
ros::Subscriber<std_msgs::UInt16> sub("motor_right_back", motor_rb);


void moter_rf( const std_msgs::UInt16& cmd_msg){
  rightFront.motor(cmd_msg.data); //set servo angle, should be from -127 to 127  
   
  }
  
ros::Subscriber<std_msgs::UInt16> sub("motor_right_front", motor_rf);

void moter_lb( const std_msgs::UInt16& cmd_msg){
  leftBack.motor(cmd_msg.data); //set servo angle, should be from -127 to 127  
   
  }
  
ros::Subscriber<std_msgs::UInt16> sub("motor_left_back", motor_lb);

void moter_lf( const std_msgs::UInt16& cmd_msg){
  leftFront.motor(cmd_msg.data); //set servo angle, should be from -127 to 127  
   
  }
  
ros::Subscriber<std_msgs::UInt16> sub("motor_right_back", motor_rb);








void setup() {

  nh.initNode();
  nh.advertise(sensorData);
  nh.advertise(arduinoLog);
  
 SabertoothTXPinSerial.begin(9600);
 Sabertooth::autobaud(SabertoothTXPinSerial);

 
 /*Serial.begin(9600); //serial rx0 and tx 0 to pi

    /* Initialise the sensor */
  if(!bno.begin())
  {
    /* There was a problem detecting the BNO055 ... check your connections */
    
    nh.logerror("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    
    while(1);
  }
  
  delay(1000);
    
  bno.setExtCrystalUse(true);
}

void loop() {
  if(Serial.available()){
    command = Serial.readStringUntil(terminator);
  }
  switch (command.charAt(0)){
   case 'k':
    rightBack.stop();
    rightFront.stop();
    leftBack.stop();
    leftFront.stop();
    break;
   case 'm': // command syntax m motorName power(-127 to 127)
     //add motor control
     command.remove(0);
     command.remove(0);
   
     String motorName = String();
      while(command.charAt(0)!= " "){
        motorName+=command.charAt(0);
        command.remove(0);
      }
      command.remove(0);
      int power= command.toInt();
     
      if(motorName="rightBack"){
          rightBack.motor(power);
       }
      if(motorName= "rightFront"){
          rightFront.motor(power);
      }
      if(motorName= "leftBack"){
          leftBack.motor(power);
      }
      if(motorName= "leftFront"){
          leftFront.motor(power);
      }
     
     break;
   
       
      
      
    case 'i':
      Serial.println("Current: "+ String(analogRead(A0),HEX)+' '+ String(analogRead(A1),HEX)+' '+ String(analogRead(A2),HEX)+' '
      +String(analogRead(A3),HEX));
  

    }
    publishSensorData();
    nh.spinOnce();
    delay(100);
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
