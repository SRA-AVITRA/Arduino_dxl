# Arduino_dxl
All codes for Arduino Mega 2560 board and dynamixel in case of U2D2 failure.

Download Arduino library for dynamixel : Dynamixel2Arduino

Install rosserial :

sudo apt-get install ros-indigo-rosserial-arduino

sudo apt-get install ros-indigo-rosserial

rosrun rosserial_arduino make_libraries.py .

```
1. roscore
2. rosrun rosserial_python serial_node.py _port:=/dev/ttyUSB0 _baud:=57600
3. rosrun move_group subscriber.py
```
