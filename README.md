Zumo Automation Project
=======================
* The goal of this project is to
    1. Allow two ZUMO32U4 robots to play a  [mini sumo match]( https://www.youtube.com/watch?v=iL8IRF4wQmU)
    2. Have the robots know who won  
    3. Enable the robots to wirelessly communicate match data to a master laptop  
    4. Allow the robots to charge themselves wirelessly  
    5. Allow the robots to reset for a new match automatically  
    6. Create a machine learning exercise whereby the robots can learn the best strategy by playing each other  
    7. Provide Brandeis students with an introduction to programming

* Getting started
 + [Link to install all software](https://brandeismakerlab.dozuki.com/Guide/Getting+Started+with+Zumo+Automation+Project/27?lang=en)

* Background information
	+ [Rules of mini sumo](http://robogames.net/rules/all-sumo.php)
* Robot used	
	+ [current robot used, ZUMO32U4](https://www.pololu.com/docs/0J63/all)
	+ [sec6ndary robot used](https://www.pololu.com/product/2504)
	+ [3d printed robot model which we want to switch to](https://www.thingiverse.com/thing:2662828)
* Software Used
	+ [Arduino Integrated Development Enviornment](https://www.arduino.cc/en/Main/Software) used to download programs to the robot
	+ [ZUMO32U4 robot library](http://pololu.github.io/zumo-32u4-arduino-library/) used to interface with the robot)
	+ We had our first meeting!
	
* This project was conceived of by technical advisor Tim Hebert and is currently being implemented by the Brandeis Robotics Club
* We are always looking for anyone who wants to contribute, email us!  
    + jsmith2021@brandeis.edu  
    + [The Brandeis University Makerlab](http://brandeismakerlab.com/people/) 

# Drive Library

- This Library Provides Wrapper Functions for the ZUMO32U4 Motors Class  
  - It is designed to work on the [ZUMO32U4 robot](https://www.pololu.com/docs/0J63/all) using the [Arduino Integrated Development Enviornment](https://www.arduino.cc/en/Main/Software)
- The functions are outlined in the header file  
  - They consist of driving, turning, and stopping functions 
  - which can be used either as a step in a sequence or integrated into more advanced programs
- An example file is provided
  - It uses the simplified robot commands to drive, turn, and stop for half a second    

[The dependency library may be found here](http://pololu.github.io/zumo-32u4-arduino-library/)  

# LineCalibrator Library

- This Library Allows the Line Sensors of the Zumo 32U4 robot to be calibrated 

  - It is designed to work on the [ZUMO robot for arduino](https://www.pololu.com/product/2506) using the [Arduino Integrated Development Enviornment](https://www.arduino.cc/en/Main/Software)

- The functions are outlined in the header file  

  - They are used to have the robot travel over all the colors it is supposed to sense 
  - and then calculate threshold values between the regions
  - the calibration function is designed to work with any colors in any order, as long as they can be read differently enough

- An example file is provided

  - It uses a LineSensor object to find the threshold values for a zumo ring

  # LineGlobal Library

  - A library that uses calclates thresholds to know what region the robot line sensors are over 
    - It is designed to work on the [ZUMO robot for arduino](https://www.pololu.com/product/2506) using the [Arduino Integrated Development Enviornment](https://www.arduino.cc/en/Main/Software)
  - The functions are outlined in the header file  
    - They allow the robot to determine what region it is over
    - given an array of region names and thresholds, 	as well as an array of the priority of regions.

# LineShield Library

- This Library Provides Wrapper Functions for the ZUMO32U4LineSensors Class  
  - It is designed to work on the [ZUMO robot for arduino](https://www.pololu.com/product/2506) using the [Arduino Integrated Development Enviornment](https://www.arduino.cc/en/Main/Software)
- The functions are outlined in the header file  
  - They are used to return whether the robot is on a line of tape and to print line sensor readings to the robot's display 
  - The boolean methods of the class are isInRing, isOnEdge, isOutBounds
  - The getRegion method returns where the robot is in the ring
  - The printAllSensors method displays the 3 used line sensor values on the robot's lcd 
- An example file is provided
  - It uses this library and the Drive library to keep the robot in a ring of tape
  - The complex navigation program uses an extra line of tape on the outside of the ring to allow the robot to know when it lost a match

# Sorter Library

- This Library sorts a given array, which is useful in calibrating the line sensors
- An example file is provided
  - It sorts 3 example arrays in a similar format to how theyd be used in a line sensor application

# Timer Library

- This library is a wrapper class for the [Arduino time function](https://www.arduino.cc/reference/en/language/functions/time/millis/)
- This library allows for the instantiation of a timer object which can return the current time, be reset, and be used on an interval
- This allows an arduino board to continually perform an update procedure without the use of delay statements
- The provided example file shows the suggested use of this class on a [ZUMO32U4 robot](https://www.pololu.com/docs/0J63/all) using the [Arduino Integrated Development Enviornment](

-The Brandeis University Robotics Club  

<img src="https://a.pololu-files.com/picture/0J6721.1200.jpg?f23bb5e39014c5721350a43b8c0e8fe4" width="200" height="200">

![Brandeis University Logo](https://www.brandeis.edu/communications/creative/downloads/gotham-outlined.jpg)