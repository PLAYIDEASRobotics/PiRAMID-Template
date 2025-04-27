#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen.
brain  Brain;

//The motor constructor takes motors as (port, ratio, reversed), so for example
//motor LeftFront = motor(PORT1, ratio6_1, false);
motor LF(PORT13,ratio6_1,true);
motor LM(PORT9,ratio6_1);
motor LB(PORT20,ratio6_1,true);

motor_group Left(LF,LM,LB);

motor RF(PORT17,ratio6_1);
motor RM(PORT4,ratio6_1, true);
motor RB(PORT12,ratio6_1);

motor_group Right(RF,RM,RB);

controller cntl;

////// VERY IMPORTANT //////
////// VERY IMPORTANT //////
////// VERY IMPORTANT //////

//Add your devices below, and don't forget to do the same in robot-config.h:


void vexcodeInit( void ) {
  // nothing to initialize
}