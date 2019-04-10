/*
 * Enum Implementation of Drive Functions so many classes can use it
 * Jacob Smith Brandeis Robotics Club
 * Modoifed from:https://stackoverflow.com/questions/1965249/how-to-write-a-java-enum-like-class-with-multiple-data-fields-in-c
 */

//set up the header file
#ifndef MotionEnums_h
#define MotionEnums_h
#include<MotionEnums.h>

class MotionEnums{

	private:
		//creates a new Motion Enum
		MotionEnums(int leftPowerMult, int rightPowerMult);
		//the left power multiplier
		int leftPowerMult;
		//the right power multiplier
	    int rightPowerMult;
	public:

	    //static instances of all the possible tank Driving combinations
	    static const MotionEnums driveBackward		=MotionEnums(-1,-1);
	    static const MotionEnums pivotLeftBackward	=MotionEnums(-1,0);
	    static const MotionEnums turnLeft			=MotionEnums(-1,1);
	    static const MotionEnums pivotRightBackward	=MotionEnums(0,-1);
	    static const MotionEnums driveStop			=MotionEnums(0,0);
	    static const MotionEnums pivotLeftForward	=MotionEnums(-1,-1);
	    static const MotionEnums turnRight			=MotionEnums(1,-1);
	    static const MotionEnums pivotRightForward	=MotionEnums(1,0);
	    static const MotionEnums driveForward		=MotionEnums(1,1);
};

#endif
