#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_, unsigned int i_range) {
  Kp = Kp_;
  Ki = Ki_;
  Kd = Kd_;
  prev_cte = 0;
  prev_ctes.assign(i_range, 0.0);
}

void PID::UpdateError(double cte) {

  double icte = 0;
  prev_ctes.push_back(cte);
  prev_ctes.pop_front();
  for(int i = 0; i < prev_ctes.size(); i++){
    icte += prev_ctes[i];
  }

  p_error = Kp * cte; 
  d_error = Kd * (cte - prev_cte);
  i_error = Ki * icte/prev_ctes.size();

  prev_cte = cte;

}

double PID::TotalError() {
  return p_error + d_error + i_error;
}
