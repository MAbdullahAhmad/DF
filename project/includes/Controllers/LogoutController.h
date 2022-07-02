#ifndef CONTROLLER_LOGOUT_H
#define CONTROLLER_LOGOUT_H

#include "iostream"
#include "../Session.h"
#include "../MasterController.h"
#include "../OutputManager.h"
#include "../Models/User.h"

using namespace std;
using namespace SessionSpace;

//> WelcomeController class
class LogoutController : public MasterController{
  private:
    OutputManager* output_manager;

  public:
    LogoutController(){
      output_manager  = nullptr;
    }

    string fire(){
      this->output_manager = new OutputManager();

      return _logout();
      return "exit";
    }

    string _logout(){
      string cmd;

      session->put("_auth_login", "0");

      // Confirm
      LogoutUser:
      this->output_manager->start();
      this->output_manager->feed();
      this->output_manager->feed("Logged out Successfully!");
      this->output_manager->command("__RIGHT__");
      this->output_manager->feed("[H] Homepage  [L] Login");
      this->output_manager->command("__END_RIGHT__");
      this->output_manager->end(); cout << "\n";

      // Command Handeling
      cmd = get_command();
      if ( // Cancel
        is_command(cmd, "H")
      ) return "homepage";
      else if ( // Retry
        is_command(cmd, "L")
      ) return "login";
      else { // Invalid
        cout << "\nInvalid Choice! Retry..\n";
        goto LogoutUser;
      }

      return "";
    }
};

#endif