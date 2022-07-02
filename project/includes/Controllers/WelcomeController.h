#ifndef CONTROLLER_WELCOME_H
#define CONTROLLER_WELCOME_H

#include "iostream"
#include "../MasterController.h"
#include "../OutputManager.h"

using namespace std;

//> WelcomeController class
class WelcomeController : public MasterController{
  private:
    OutputManager* output_manager;

  public:
    WelcomeController(){
      output_manager = nullptr;
    }

    string fire(){
      output_manager = new OutputManager;
      welcome_animation();
      return "homepage";
    }

    void welcome_animation(){
      this->output_manager->welcome();
    }
};

#endif