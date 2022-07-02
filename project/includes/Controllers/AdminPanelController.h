#ifndef CONTROLLER_ADMIN_PANEL_H
#define CONTROLLER_ADMIN_PANEL_H

#include "iostream"
#include "../MasterController.h"
#include "../OutputManager.h"
#include "../Pages/AdminPanel.h"
#include "../Models/User.h"

using namespace std;

//> WelcomeController class
class AdminPanelController : public MasterController{
  private:
    OutputManager* output_manager;
    AdminPanel* admin_panel;

  public:
    AdminPanelController(){
      output_manager  = nullptr;
      admin_panel     = nullptr;
    }

    string fire(){
      string cmd;

      this->output_manager = new OutputManager();
      this->admin_panel = new AdminPanel();

      return _admin_panel();
      return "exit";
    }

    string _admin_panel(){
      string cmd;

      // Execute Page
      this->output_manager->execute(this->admin_panel);

      // Command Handeling
      GetCommand:
      cmd = get_command();
      if ( // Cancel
        is_command(cmd, "U")
      ) return "admin_Users";
      else if ( // Retry
        is_command(cmd, "C")
      ) return "admin_channels";
      else if ( // Retry
        is_command(cmd, "A")
      ) return "admin_admins";
      else if ( // Retry
        is_command(cmd, "L")
      ) return "logout";
      else { // Invalid
        cout << "\nInvalid Choice! Retry..\n";
        this->admin_panel->commands();
        this->output_manager->execute(this->admin_panel);
        goto GetCommand;
      }
      return "";
    }
};

#endif