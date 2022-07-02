#ifndef CONTROLLER_SIGNUP_H
#define CONTROLLER_SIGNUP_H

#include "iostream"
#include "../MasterController.h"
#include "../OutputManager.h"
#include "../Pages/Signup.h"

using namespace std;

//> WelcomeController class
class SignupController : public MasterController{
  private:
    OutputManager* output_manager;
    Signup* signup;

  public:
    SignupController(){
      output_manager  = nullptr;
      signup          = nullptr;
    }

    string fire(){
      this->output_manager = new OutputManager();
      this->signup = new Signup(false);

      return _signup();
      return "exit";
    }

    string _signup(){
      string command;

      this->signup->run();
      this->output_manager->execute(this->signup);
      return "";
    }
};

#endif