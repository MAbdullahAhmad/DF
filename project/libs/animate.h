#ifndef ANIMATE_H
#define ANIMATE_H

#include "iostream"
using namespace std;

// Configurations
#define default_delay 5

void delay(int millis){
  // @pending-code
}
void animate_text(string text, int delay){
  cout << text;
}
void animate_text(string text){
  animate_text(text, default_delay);
}
void clear(){
  system("clear");
}

#endif