/*
 * Enum Implementation of Drive Functions so many classes can use it
 * Jacob Smith Brandeis Robotics Club
 */

#include "MotionEnums.h"

//creates a new Motion Enum Object
MotionEnums::MotionEnums(int leftPowerMult, int rightPowerMult) {
        this->leftPowerMult = leftPowerMult;
        this->rightPowerMult=rightPowerMult;
}
// Properties and methods go here
