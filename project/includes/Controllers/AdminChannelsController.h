#ifndef CONTROLLER_ADMIN_CHANNELS_H
#define CONTROLLER_ADMIN_CHANNELS_H

#include "iostream"
#include "../MasterController.h"
#include "../OutputManager.h"
#include "../Pages/AdminChannels.h"
#include "../Models/User.h"

using namespace std;

//> WelcomeController class
class AdminChannelsController : public MasterController{
  private:
    OutputManager* output_manager;
    AdminChannels* admin_channels;

  public:
    AdminChannelsController(){
      output_manager  = nullptr;
      admin_channels          = nullptr;
    }

    string fire(){
      this->output_manager = new OutputManager();
      this->admin_channels = new AdminChannels(false);

      return _admin_channels();
      return "exit";
    }

    string _admin_channels(){
      string cmd;
      return "";
    }
};

#endif