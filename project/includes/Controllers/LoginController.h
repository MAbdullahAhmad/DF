#ifndef CONTROLLER_LOGIN_H
#define CONTROLLER_LOGIN_H

#include "iostream"
#include "cstring"
#include "../Session.h"
#include "../MasterController.h"
#include "../OutputManager.h"
#include "../Pages/Login.h"
#include "../Models/User.h"

using namespace std;
using namespace SessionSpace;

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
      session = new Session;
      string cmd;
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
      // delay_seconds(2); //@debug

      int l=0;
      User* u = new User;
      for(User t : u->crud()->all())
        if(l = t.verify(username, password)){
          cout << "";
          session->put("_auth_login", to_string(l));
          break;
        } else cout << "";

      if(l == 0){
        // Confirm
        LoginFailed:
        this->output_manager->start();
        this->output_manager->feed();
        this->output_manager->feed("Incorrect Username or Password.");
        this->output_manager->command("__RIGHT__");
        this->output_manager->feed("[R] Retry  [B] Back to Homepage");
        this->output_manager->command("__END_RIGHT__");
        this->output_manager->end(); cout << "\n";

        // Command Handeling
        cmd = get_command();
        if ( // Cancel
          is_command(cmd, "R")
        ) return "login";
        else if ( // Retry
          is_command(cmd, "B")
        ) return "homepage";
        else { // Invalid
          cout << "\nInvalid Choice! Retry..\n";
          goto LoginFailed;
        }
      }

      // cout << (session->get("_auth_login") == "1" ? "main_form" : "admin_panel") << "\n"; //@debug
      return l == 1 ? "main_form" : "admin_panel";
    }
};

#endif