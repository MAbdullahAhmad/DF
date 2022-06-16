#ifndef STRING_H
#define STRING_H

#include "iostream"
using namespace std;

void repeat_str(string s, int count){
  for(int i=0; i<count; i++){
    cout << s;
  }
}
void repeat_chr(char c, int count){
  for(int i=0; i<count; i++){
    cout << c;
  }
}

#endif