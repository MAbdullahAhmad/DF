#ifndef CONTROLLER_MAIN_FORM_H
#define CONTROLLER_MAIN_FORM_H

#include "iostream"
#include "../MasterController.h"
#include "../OutputManager.h"
#include "../Pages/MainForm.h"
#include "../Models/User.h"

using namespace std;

//> WelcomeController class
class MainFormController : public MasterController{
  private:
    OutputManager* output_manager;
    MainForm* main_form;

  public:
    MainFormController(){
      output_manager  = nullptr;
      main_form          = nullptr;
    }

    string fire(){
      this->output_manager = new OutputManager();
      this->main_form = new MainForm(false);

      return _main_form();
      return "exit";
    }

    string _main_form(){
      string cmd;
      return "";
    }
};

#endif