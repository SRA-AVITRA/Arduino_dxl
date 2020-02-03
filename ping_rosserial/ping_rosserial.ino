/*******************************************************************************
* Copyright 2016 ROBOTIS CO., LTD.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

#include <Dynamixel2Arduino.h>
//#include <ros.h>
//#include <sensor_msgs/JointState.h>
//#include <std_msgs/Float32MultiArray.h>
#define NUM_MOTORS 6
#define DXL_SERIAL   Serial1
#define DEBUG_SERIAL Serial
const uint8_t DXL_DIR_PIN = 2; // DYNAMIXEL Shield DIR PIN
uint8_t DXL_ID = 1;
const float DXL_PROTOCOL_VERSION = 1.0;

Dynamixel2Arduino dxl(DXL_SERIAL, DXL_DIR_PIN);


float angles[6] = {0, 0, 0, 0, 0 ,0};

//void angleCb(std_msgs::Float32MultiArray data)
//{
//  for(int i=0;i<NUM_MOTORS;i++)
//  {
//    angles[i] = ((data.data[i] * 4068.0) / 71.0);   
//  }
//}

//ros::NodeHandle nh;

//ros::Subscriber<std_msgs::Float32MultiArray> sub("/move_group/fake_controller_joint_states", &angleCb );

void ping()
{
  for(uint8_t i=0;i<250;i++)
  {
  
    DXL_ID = i;
    DEBUG_SERIAL.print("PROTOCOL ");
    DEBUG_SERIAL.print(DXL_PROTOCOL_VERSION, 1);
    DEBUG_SERIAL.print(", ID ");
    DEBUG_SERIAL.print(DXL_ID);
    DEBUG_SERIAL.print(": ");
    if(dxl.ping(DXL_ID) == true){
      DEBUG_SERIAL.print("ping succeeded!");
      DEBUG_SERIAL.print(", Model Number: ");
      DEBUG_SERIAL.println(dxl.getModelNumber(DXL_ID));
    }else{
      DEBUG_SERIAL.println("ping failed!");
    }
    delay(500);
  }
}


void setup() 
{
  // Use Serial to debug.
  DEBUG_SERIAL.begin(115200);

  // Set Port baudrate to 57600bps. This has to match with DYNAMIXEL baudrate.
  dxl.begin(1000000);
  // Set Port Protocol Version. This has to match with DYNAMIXEL protocol version.
  dxl.setPortProtocolVersion(DXL_PROTOCOL_VERSION);
//  nh.initNode();
//  nh.subscribe(sub);
  DEBUG_SERIAL.println("I am in setup");
}

void loop() 
{
//  for(int i=0;i<NUM_MOTORS;i++)
//  {
//    DEBUG_SERIAL.print(i);DEBUG_SERIAL.print(" : ");
//    DEBUG_SERIAL.println(angles[i]);
//  }
//  nh.spinOnce();
//  delay(100);
    for(uint8_t i=0;i<250;i++)
  {
  
    DXL_ID = i;
    DEBUG_SERIAL.print("PROTOCOL ");
    DEBUG_SERIAL.print(DXL_PROTOCOL_VERSION, 1);
    DEBUG_SERIAL.print(", ID ");
    DEBUG_SERIAL.print(DXL_ID);
    DEBUG_SERIAL.print(": ");
    if(dxl.ping(DXL_ID) == true){
      DEBUG_SERIAL.print("ping succeeded!");
      DEBUG_SERIAL.print(", Model Number: ");
      DEBUG_SERIAL.println(dxl.getModelNumber(DXL_ID));
    }else{
      DEBUG_SERIAL.println("ping failed!");
    }
    delay(500);
  }
}
