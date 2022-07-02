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
      admin_panel          = nullptr;
    }

    string fire(){
      this->output_manager = new OutputManager();
      this->admin_panel = new AdminPanel(false);

      return _admin_panel();
      return "exit";
    }

    string _admin_panel(){
      string cmd;
      return "";
    }
};

#endif