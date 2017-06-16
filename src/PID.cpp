#include "PID.h"

//DEBUG
#include <iostream>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double kp, double ki, double kd) {
  Kp = kp;
  Ki = ki;
  Kd = kd;


  current_time = time(0);
  last_time = current_time;
  Clear();
}

void PID::UpdateError(double cte) {

  totoal_error += cte;

  current_time = time(0);
  double delta_t = current_time - last_time;
  double delta_err = cte - last_error;

  p_error = cte;
  i_error += cte * delta_t;

  if(i_error >= windup_guard)
    i_error = -windup_guard;
  
  else if(i_error > windup_guard)
    i_error = windup_guard;

  d_error = 0;
  if(delta_t > 0)
    d_error = delta_err / delta_t;
  
  last_time = current_time;
  last_error = cte;
}

void PID::Clear(){
  p_error = 0;
  i_error = 0;
  d_error = 0;

  last_error = 0;
  init_error = 0;
  windup_guard = 20;
  
  output = 0;
}

double PID::TotalError() {

  double steer = -Kp * p_error - Ki * i_error - Kd * d_error;

  if(steer > 1.0) steer = 1.0;
  if(steer < -1.0) steer = -1.0;

  return steer;
}

