#ifndef PID_H
#define PID_H

#include <ctime>

class PID {
public:
  /*
  * Errors
  */
  double p_error;
  double i_error;
  double d_error;

  /*
  * Time
  */
  long double current_time;
  long double last_time;

  /*
  * Coefficients
  */ 
  double Kp;
  double Ki;
  double Kd;

  /*
  * Errors
  */
  
  double last_error;
  double init_error;
  double totoal_error;

  double windup_guard;
  double output;


  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double Kp, double Ki, double Kd);

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);

  /*
  * Calculate the total PID error.
  */
  double TotalError();

  /*
  * Clear internal parameters
  */
  void Clear();
};

#endif /* PID_H */
