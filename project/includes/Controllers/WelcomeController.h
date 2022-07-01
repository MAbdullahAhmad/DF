#ifndef CONTROLLER_WELCOME_H
#define CONTROLLER_WELCOME_H

#include "iostream"
#include "../MasterController.h"

using namespace std;

//> WelcomeController class
class WelcomeController : public MasterController{
  private:

  public:
    WelcomeController(){
      cout << "WelcomeController\n";
    }

    string fire(){
      cout << "Fire WC\n";
      return "welcome";
    }
};

#endif