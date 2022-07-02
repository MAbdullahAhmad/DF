#ifndef CONTROLLER_ADMIN_USERS_H
#define CONTROLLER_ADMIN_USERS_H

#include "iostream"
#include "../MasterController.h"
#include "../OutputManager.h"
#include "../Pages/AdminUsers.h"
#include "../Models/User.h"

using namespace std;

//> WelcomeController class
class AdminUsersController : public MasterController{
  private:
    OutputManager* output_manager;
    AdminUsers* admin_users;

  public:
    AdminUsersController(){
      output_manager  = nullptr;
      admin_users          = nullptr;
    }

    string fire(){
      this->output_manager = new OutputManager();
      this->admin_users = new AdminUsers(false);

      return _admin_users();
      return "exit";
    }

    string _admin_users(){
      string cmd;
      return "";
    }
};

#endif