/*
 * MotionEnums.h
 *
 *  Created on: Apr 5, 2019
 *      Author: jsmit
 */
s
#ifndef MotionEnums_h
#define MotionEnums_h
#include<MotionEnums.h>

class MotionEnums{

	private:
		MotionEnums(int leftPowerMult, int rightPowerMult);
		int leftPowerMult;
	    int rightPowerMult;
	public:

	    // Enum value DECLARATIONS - they are defined later
	    static const MotionEnums driveForward	=MotionEnums(1,1);
	    static const MotionEnums driveBackward	=MotionEnums(1,1);
	    static const MotionEnums pivotRight		=MotionEnums(1,1);
	    static const MotionEnums pivotLeft		=MotionEnums(1,1);
	    static const MotionEnums turnRight		=MotionEnums(1,1);
	    static const MotionEnums turnLeft		=MotionEnums(1,1);
	    static const MotionEnums stopDrive		=MotionEnums(1,1);
};

#endif
