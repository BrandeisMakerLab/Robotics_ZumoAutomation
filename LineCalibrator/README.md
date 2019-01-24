LineClibrator Library
=============
+ This Library Allows the Line Sensors of the Zumo 32U4 robot to be calibrated 
    + It is designed to work on the [ZUMO robot for arduino](https://www.pololu.com/product/2506) using the [Arduino Integrated Development Enviornment](https://www.arduino.cc/en/Main/Software)
+ The functions are outlined in the header file  
    + They are used to have the robot travel over all the colors it is supposed to sense 
	+ and then calculate threshold values between the regions
	+ the calibration function is designed to work with any colors in any order, as long as they can be read differently enough
+ An example file is provided
    + It uses a LineSensor object to find the threshold values for a zumo ring

-The Brandeis University Robotics Club
![Brandeis University Logo](https://www.brandeis.edu/communications/creative/downloads/gotham-outlined.jpg)
