#ifndef CONTROLLER_CHANNELS_H
#define CONTROLLER_CHANNELS_H

#include "iostream"
#include "../MasterController.h"
#include "../OutputManager.h"
#include "../Pages/Channels.h"
#include "../Models/User.h"

using namespace std;

//> WelcomeController class
class ChannelsController : public MasterController{
  private:
    OutputManager* output_manager;
    Channels* channels;

  public:
    ChannelsController(){
      output_manager  = nullptr;
      channels          = nullptr;
    }

    string fire(){
      this->output_manager = new OutputManager();
      this->channels = new Channels(false);

      return _channels();
      return "exit";
    }

    string _channels(){
      string cmd;
      return "";
    }
};

#endif