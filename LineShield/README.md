Line Library
=============
+ This Library Provides Wrapper Functions for the ZUMO32U4LineSensors Class  
    + It is designed to work on the [ZUMO robot for arduino](https://www.pololu.com/product/2506) using the [Arduino Integrated Development Enviornment](https://www.arduino.cc/en/Main/Software)
+ The functions are outlined in the header file  
    + They are used to return whether the robot is on a line of tape and to print line sensor readings to the robot's display 
	+ The boolean methods of the class are isInRing, isOnEdge, isOutBounds
	+ The getRegion method returns where the robot is in the ring
	+ The printAllSensors method displays the 3 used line sensor values on the robot's lcd 
+ An example file is provided
    + It uses this library and the Drive library to keep the robot in a ring of tape
	+ The complex navigation program uses an extra line of tape on the outside of the ring to allow the robot to know when it lost a match

[The dependency library may be found here](http://pololu.github.io/zumo-32u4-arduino-library/)  
 
-The Brandeis University Robotics Club
![Brandeis University Logo](https://www.brandeis.edu/communications/creative/downloads/gotham-outlined.jpg)
