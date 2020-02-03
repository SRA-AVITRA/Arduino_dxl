#include <Dynamixel2Arduino.h>
#include <actuator.h>

/*
 * rosserial Subscriber Example
 * Blinks an LED on callback
 */

#include <ros.h>
#include <std_msgs/Empty.h>
//#include <sensor_msgs/JointState.h>
#include <std_msgs/Float32MultiArray.h>
#define NUM_MOTORS 6
#define DXL_SERIAL   Serial1
const uint8_t DXL_DIR_PIN = 2; // DYNAMIXEL Shield DIR PIN

uint8_t DXL_ID = 1;
const float DXL_PROTOCOL_VERSION = 1.0;

Dynamixel2Arduino dxl(DXL_SERIAL, DXL_DIR_PIN);

ros::NodeHandle nh;

float angles[6] = {100, 0, 0, 0, 0 ,0};

void messageCb( const std_msgs::Float32MultiArray& toggle_msg){
  digitalWrite(12, HIGH-digitalRead(12));   // blink the led
  for(int i=0;i<NUM_MOTORS;i++)
  {
    angles[i] = ((toggle_msg.data[i] * 4068.0) / 71.0);  
  }
}

ros::Subscriber<std_msgs::Float32MultiArray> sub("angles", &messageCb );

void setup()
{
  pinMode(12, OUTPUT);
  dxl.begin(1000000);
  // Set Port Protocol Version. This has to match with DYNAMIXEL protocol version.
  dxl.setPortProtocolVersion(DXL_PROTOCOL_VERSION);
  nh.initNode();
  nh.subscribe(sub);
}

void loop()
{
  nh.spinOnce();
  dxl.setGoalPosition(DXL_ID, angles[0], UNIT_DEGREE);

}
