#ifndef STRING_H
#define STRING_H

#include "iostream"
#include "vector"
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

string get_repeat_str(string s, int count){
  string tmp;
  for(int i=0; i<count; i++){
    tmp += s;
  }
  return tmp;
}
string get_repeat_chr(char c, int count){
  string tmp;
  for(int i=0; i<count; i++){
    tmp += c;
  }
  return tmp;
}

#endif