#include "vex.h"

/**
 * Resets the constants for auton movement.
 * Modify these to change the default behavior of functions like
 * drive_distance(). For explanations of the difference between
 * drive, heading, turning, and swinging, as well as the PID and
 * exit conditions, check the docs.
 * Do not change the constant functions
 * Only edit the parameters inside
 */

void default_constants(){
  // Each constant set is in the form of (maxVoltage, kP, kI, kD, startI).
  chassis.set_drive_constants(10, 1.5, 0, 10, 0);
  chassis.set_heading_constants(6, .4, 0, 1, 0);
  chassis.set_turn_constants(12, .2, .03, 3, 15);
  chassis.set_swing_constants(12, .3, .001, 2, 15);

  // Each exit condition set is in the form of (settle_error, settle_time, timeout).
  chassis.set_drive_exit_conditions(1.5, 300, 5000);
  chassis.set_turn_exit_conditions(1, 300, 3000);
  chassis.set_swing_exit_conditions(1, 300, 3000);
}

/**
 * Sets constants to be more effective for odom movements.
 * For functions like drive_to_point(), it's often better to have
 * a slower max_voltage and greater settle_error than you would otherwise.
 */

void odom_constants(){
  default_constants();
  chassis.heading_max_voltage = 10;
  chassis.drive_max_voltage = 8;
  chassis.drive_settle_error = 3;
  chassis.boomerang_lead = .5;
  chassis.drive_min_voltage = 0;
}

/**
 * Make auton functions below this line to be used later
 * ie. intake spin functions, or arm raise to certain height function
 * void intake(){
 *  intakeMotor.spin(fwd,12,volt);
 * }
 */





/**
 * Default auton
 * Make new autons by creating a new function
 * Add those new autons to autons.h in the include folder
 * Then change the autons and pre autons in main.cpp
 */


void Default(){
  chassis.drive_distance(12);
  chassis.turn_to_angle(90);
  chassis.drive_distance(6);
  chassis.right_swing_to_angle(0);
  chassis.left_swing_to_angle(180);
}