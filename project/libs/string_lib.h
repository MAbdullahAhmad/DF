#ifndef STRING_H
#define STRING_H

#include "iostream"
#include "foreach.h"

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

void str_to_lower(string &str){

  for_each(str.begin(), str.end(), [](char & c){
    c = ::tolower(c);
  });
}

void str_to_upper(string &str){
  for_each(str.begin(), str.end(), [](char & c){
    c = ::toupper(c);
  });
}

void get_to_lower(string str){
  return str_to_lower(str);
}

void get_to_upper(string str){
  return str_to_upper(str);
}

#endif