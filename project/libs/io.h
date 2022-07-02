#ifndef IO_H
#define IO_H

#include "iostream"

using namespace std;

string getline(){
  string line;
  getline(cin >> ws, line);
  return line;
}

#endif