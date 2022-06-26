#ifndef DELAY_H
#define DELAY_H

#include "iostream"
#include "math.h"
#include "chrono"
#include "thread"

using namespace std;

// Master Func
void s_for(int t){
  using namespace std::this_thread;
  using namespace std::chrono;

  sleep_for(
    nanoseconds(t)
  );
}

// Levels : to put in master
void delay_seconds(double t){
  s_for((int)(t * pow(10, 9)));
}
void delay_millis(double t){
  s_for((int)(t * pow(10, 6)));
}

#endif