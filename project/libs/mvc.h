#ifndef MVC_H
#define MVC_H

#include "iostream"
#include "string_lib.h"

using namespace std;

string get_command(){
  cout << "\nEnter Command: ";
  return getline();
}

bool is_command(string inp_command, string command, bool strict){
  return (
    inp_command == command
  ) || (
    !strict && (
      inp_command.substr(0, inp_command.length()) == command
    )
  );
}
bool is_command(string inp_command, string command){
  return is_command(inp_command, command, false);
}

// In Full String Commands
bool in_commands(string cmd, vector<string> commands, bool strict){
  for(string _cmd : commands){
    if(is_command(cmd, _cmd, strict))
      return true;
  }
  return false;
}
bool in_commands(string cmd, vector<string> commands){
  return in_commands(cmd, commands, false);
}

// In One Character Commands
bool in_ch_commands(string cmd, vector<string> commands, bool strict){
  for(string _cmd : commands){
    if(is_command(cmd, _cmd.substr(0, 1), strict))
      return true;
  }
  return false;
}
bool in_ch_commands(string cmd, vector<string> commands){
  return in_ch_commands(cmd, commands, false);
}

#endif