
#include <ros.h>
#include <math.h>

#include <Wire.h>
#include <SoftwareSerial.h>

#include <Sabertooth.h>

#include <std_msgs/String.h>
#include <geometry_msgs/Twist.h>

// function predefs
void cmdVelCallback(const geometry_msgs::Twist&);
void stop();
void move(int, int);

// global hardware vars
SoftwareSerial portROS(0, 1);

Sabertooth back(128, Serial1);
Sabertooth front(129, Serial1);

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

String debug_str;


void setup() {
  // put your setup code here, to run once:
  Serial1.begin(9600);
  portROS.begin(57600);

  nh.initNode();
  nh.subscribe(vel_sub);

  nh.advertise(chatter_pub);
  nh.advertise(sensorData);
  nh.advertise(arduinoLog);
  nh.advertise(currentData);

  move(10, 10);
}

void loop() {
  // put your main code here, to run repeatedly:
  nh.spinOnce();

  dt = millis() - last_time;

  if(dt > 100) {
    move(10, 10);
  }

//  Serial1.write(69);
//  front.motor(1, 0);
//  front.motor(2, 100);
  // move(100, 100);
  Serial1.flush();


  delay(10);
}

char buf[128];


void cmdVelCallback(const geometry_msgs::Twist& twist) {
  last_time = millis();
  
  const float linear = twist.linear.x;
  const float spin = twist.angular.z;

  sprintf(buf, "Vals: %0.2f,%0.2f", linear, spin);
  nh.logerror(buf);

  // TODO: Figure this out
  const int left = linear + spin;
  const int right = linear - spin;

  move(left, right);
  Serial1.flush();
}

void move(int left, int right) {
  sprintf(buf, "Setting Motors -- Left: %3d, Right: %3d", left, right);
  nh.logerror(buf);
  front.motor(1, left);
  back.motor(1, left);

  front.motor(2, right);
  back.motor(2, right);
}

void stop() {
  move(0, 0);
}
