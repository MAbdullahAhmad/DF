#ifndef CONTROLLER_LOGOUT_H
#define CONTROLLER_LOGOUT_H

#include "iostream"
#include "../MasterController.h"
#include "../OutputManager.h"
#include "../Models/User.h"

using namespace std;

//> WelcomeController class
class LogoutController : public MasterController{
  private:
    OutputManager* output_manager;

  public:
    LogoutController(){
      output_manager  = nullptr;
      logout          = nullptr;
    }

    string fire(){
      this->output_manager = new OutputManager();

      return _logout();
      return "exit";
    }

    string _logout(){
      string cmd;
      return "";
    }
};

#endif