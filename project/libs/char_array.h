#ifndef CHAR_ARRAY_H
#define CHAR_ARRAY_H

#include "iostream"

using namespace std;

void deep_copy(char* container, char* object, int size){
  for(int i=0; i<size; i++){
    container[i] = object[i];
    if(object[i] == '\0'){
      break;
    }
  }
}

void deep_copy(char* container, const char* object, int size){
  for(int i=0; i<size; i++){
    container[i] = object[i];
    if(object[i] == '\0'){
      break;
    }
  }
}

#endif