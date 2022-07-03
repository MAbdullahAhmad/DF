#ifndef CONTROLLER_ABOUT_H
#define CONTROLLER_ABOUT_H

#include "iostream"
#include "../Session.h"
#include "../MasterController.h"
#include "../OutputManager.h"
#include "../Pages/About.h"

using namespace std;
using namespace SessionSpace;

//> WelcomeController class
class AboutController : public MasterController{
  private:
    OutputManager* output_manager;
    About* about;

  public:
    AboutController(){
      output_manager  = nullptr;
      about = nullptr;
    }

    string fire(){
      this->output_manager = new OutputManager();
      this->about = new About();

      return _logout();
      return "exit";
    }

    string _logout(){
      string cmd;

      this->output_manager->execute(about);

      // Command Handeling
      CommandsControl:
      cmd = get_command();
      if ( // Cancel
        is_command(cmd, "B")
      ) return "homepage";
      else { // Invalid
        cout << "\nInvalid Choice! Retry..\n";
        goto CommandsControl;
      }

      return "";
    }
};

#endif