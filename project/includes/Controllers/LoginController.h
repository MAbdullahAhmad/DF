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
      string username;
      string password;

      // Login Top
      this->login->run();
      this->output_manager->execute(this->login);
      cout << "\n";
      
      // Input Username
      this->output_manager->get_bm()->upload(); cout << "\n";
      this->output_manager->get_bm()->upload();
      cout << "\t\tEnter Username: "; username = getline();

      // Input Password
      this->output_manager->get_bm()->upload();
      cout << "\t\tEnter Password: "; password = getline();
      this->output_manager->get_bm()->upload(); cout << "\n\n";

      // Authenticating Message
      this->output_manager->start();
      this->output_manager->feed();
      this->output_manager->feed("Authenticating ...");
      this->output_manager->end(); cout << "\n";
      delay_seconds(2);

      return "";
    }
};

#endif