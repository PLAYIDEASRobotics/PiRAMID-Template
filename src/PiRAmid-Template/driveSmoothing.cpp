#include "vex.h"
#include "PiRAmid-Template/lowpass.h"
//////////////////////// DRIVE SMOOTHING CODE DO NOT REMOVE DOES NOT NEED TO BE USED//////////////////////
//////////////////////// DRIVE SMOOTHING CODE DO NOT REMOVE DOES NOT NEED TO BE USED//////////////////////
//////////////////////// DRIVE SMOOTHING CODE DO NOT REMOVE DOES NOT NEED TO BE USED//////////////////////

double s_Speed = 0.0;
double s_Turn = 0.0;

void ArcadeDrive(double speed, double turn) {
  const double PCT_TO_VOLT = 12.0 / 100.0;
  Right.spin(fwd, (speed - turn) * PCT_TO_VOLT, volt);
  Left.spin(fwd, (speed + turn) * PCT_TO_VOLT, volt);
}

void SmoothArcadeDrive(double speed, double turn) {
  /*changing the filter parameter changes the smoothness*/
  static CheckLib::LowPassFilter s_SpeedFilter(0.005);
  static CheckLib::LowPassFilter s_TurnFilter(0.05);

  /* changing the accelVal below changes how fast the robot can accelerate to the max speed */
  float accelVal = 100.0;

  speed *= fabs(speed) / accelVal;

  speed = s_SpeedFilter.get(speed);
  turn = s_TurnFilter.get(turn);

  turn *= fmax(60, fabs(speed)) / 100.0;

  ArcadeDrive(speed, turn);
}

void Stop() {
  Right.stop(brake);
  Left.stop(brake);
}

void DriveSmoothing() {
  SmoothArcadeDrive(cntl.Axis3.position(),cntl.Axis1.position());
  return;
}