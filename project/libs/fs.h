#ifndef FS_H
#define FS_H

#include "iostream"
#include "unistd.h"

using namespace std;

string cwd(){
  char path[256];
  getcwd(path, 256);
  return (string)path + "/";
}

#endif