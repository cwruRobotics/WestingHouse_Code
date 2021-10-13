
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


void setup() {
 SabertoothTXPinSerial.begin(9600);
 Sabertooth::autobaud(SabertoothTXPinSerial);
 Serial.begin(9600); //serial rx0 and tx 0 to pi

    /* Initialise the sensor */
  if(!bno.begin())
  {
    /* There was a problem detecting the BNO055 ... check your connections */
    Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
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
   case 'r':
       //send sensor data packet
       //could add VECTOR_ACCELEROMETER, VECTOR_MAGNETOMETER,VECTOR_GRAVITY...
       sensors_event_t orientationData , angVelocityData , linearAccelData, magnetometerData, accelerometerData, gravityData;
       bno.getEvent(&orientationData, Adafruit_BNO055::VECTOR_EULER);
       bno.getEvent(&angVelocityData, Adafruit_BNO055::VECTOR_GYROSCOPE);
       bno.getEvent(&linearAccelData, Adafruit_BNO055::VECTOR_LINEARACCEL);
       bno.getEvent(&magnetometerData, Adafruit_BNO055::VECTOR_MAGNETOMETER);
       bno.getEvent(&accelerometerData, Adafruit_BNO055::VECTOR_ACCELEROMETER);
       bno.getEvent(&gravityData, Adafruit_BNO055::VECTOR_GRAVITY);

       printEvent(&orientationData);
       printEvent(&angVelocityData);
       printEvent(&linearAccelData);
       printEvent(&magnetometerData);
       printEvent(&accelerometerData);
       printEvent(&gravityData);
 
      int8_t boardTemp = bno.getTemp();
      Serial.println();
      Serial.print(F("temperature: "));
      Serial.println(boardTemp);

      uint8_t system, gyro, accel, mag = 0;
      bno.getCalibration(&system, &gyro, &accel, &mag);
      Serial.println();
      Serial.print("Calibration: Sys=");
      Serial.print(system);
      Serial.print(" Gyro=");
      Serial.print(gyro);
      Serial.print(" Accel=");
      Serial.print(accel);
      Serial.print(" Mag=");
      Serial.println(mag);

      Serial.println("--");
      
      break;
  

    }
    delay(100);
}

void printEvent(sensors_event_t* event) {
  double x = -1000000, y = -1000000 , z = -1000000; //dumb values, easy to spot problem
  if (event->type == SENSOR_TYPE_ACCELEROMETER) {
    Serial.print("Accl:");
    x = event->acceleration.x;
    y = event->acceleration.y;
    z = event->acceleration.z;
  }
  else if (event->type == SENSOR_TYPE_ORIENTATION) {
    Serial.print("Orient:");
    x = event->orientation.x;
    y = event->orientation.y;
    z = event->orientation.z;
  }
  else if (event->type == SENSOR_TYPE_MAGNETIC_FIELD) {
    Serial.print("Mag:");
    x = event->magnetic.x;
    y = event->magnetic.y;
    z = event->magnetic.z;
  }
  else if (event->type == SENSOR_TYPE_GYROSCOPE) {
    Serial.print("Gyro:");
    x = event->gyro.x;
    y = event->gyro.y;
    z = event->gyro.z;
  }
  else if (event->type == SENSOR_TYPE_ROTATION_VECTOR) {
    Serial.print("Rot:");
    x = event->gyro.x;
    y = event->gyro.y;
    z = event->gyro.z;
  }
  else if (event->type == SENSOR_TYPE_LINEAR_ACCELERATION) {
    Serial.print("Linear:");
    x = event->acceleration.x;
    y = event->acceleration.y;
    z = event->acceleration.z;
  }
  else if (event->type == SENSOR_TYPE_GRAVITY) {
    Serial.print("Gravity:");
    x = event->acceleration.x;
    y = event->acceleration.y;
    z = event->acceleration.z;
  }
  else {
    Serial.print("Unk:");
  }

  Serial.print("\tx= ");
  Serial.print(x);
  Serial.print(" |\ty= ");
  Serial.print(y);
  Serial.print(" |\tz= ");
  Serial.println(z);
}
