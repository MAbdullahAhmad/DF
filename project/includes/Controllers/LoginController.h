#ifndef CONTROLLER_LOGIN_H
#define CONTROLLER_LOGIN_H

#include "iostream"
#include "../MasterController.h"
#include "../OutputManager.h"
#include "../Pages/Login.h"

using namespace std;

//> WelcomeController class
class LoginController : public MasterController{
  private:
    OutputManager* output_manager;
    Login* login;

  public:
    LoginController(){
      output_manager  = nullptr;
      login           = nullptr;
    }

    string fire(){
      this->output_manager = new OutputManager();
      this->login = new Login(false);

      return _login();
      return "exit";
    }

    string _login(){
      string command;

      this->login->run();
      this->output_manager->execute(this->login);
      return "";
    }
};

#endif