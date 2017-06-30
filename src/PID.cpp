#include "PID.h"

using namespace std;

PID::PID() {}

PID::~PID() {}

void PID::Init(double kp, double ki, double kd) {
  Kp = kp;
  Ki = ki;
  Kd = kd;

  Clear();
}

void PID::UpdateError(double cte) {

  p_error = cte;
  i_error += cte;
  d_error = cte - last_error;

  last_error = cte;
}

void PID::Clear(){
  p_error = 0;
  i_error = 0;
  d_error = 0;

  last_error = 0;
}

double PID::TotalError() {

  double steer = -Kp * p_error - Ki * i_error - Kd * d_error;

  if(steer > 1.0) steer = 1.0;
  if(steer < -1.0) steer = -1.0;

  return steer;
}

