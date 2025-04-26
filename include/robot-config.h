using namespace vex;

extern brain Brain;

//To set up a motor called LeftFront here, you'd use
//extern motor LeftFront;

//Add your devices below, and don't forget to do the same in robot-config.cpp:

extern motor LF;
extern motor LM;
extern motor LB;

extern motor_group Left;

extern motor RF;
extern motor RM;
extern motor RB;

extern motor_group Right;

extern controller cntl;

void  vexcodeInit( void );