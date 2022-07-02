#ifndef CONTROLLER_ADMIN_ADMINS_H
#define CONTROLLER_ADMIN_ADMINS_H

#include "iostream"
#include "../MasterController.h"
#include "../OutputManager.h"
#include "../Pages/AdminAdmins.h"
#include "../Models/User.h"

using namespace std;

//> WelcomeController class
class AdminAdminsController : public MasterController{
  private:
    OutputManager* output_manager;
    AdminAdmins* admin_admins;

  public:
    AdminAdminsController(){
      output_manager  = nullptr;
      admin_admins          = nullptr;
    }

    string fire(){
      this->output_manager = new OutputManager();
      this->admin_admins = new AdminAdmins(false);

      return _admin_admins();
      return "exit";
    }

    string _admin_admins(){
      string cmd;
      return "";
    }
};

#endif