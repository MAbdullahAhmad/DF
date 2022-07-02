#ifndef CONTROLLER_NEW_POST_H
#define CONTROLLER_NEW_POST_H

#include "iostream"
#include "../MasterController.h"
#include "../OutputManager.h"
#include "../Pages/NewPost.h"
#include "../Models/User.h"

using namespace std;

//> WelcomeController class
class NewPostController : public MasterController{
  private:
    OutputManager* output_manager;
    NewPost* new_post;

  public:
    NewPostController(){
      output_manager  = nullptr;
      new_post          = nullptr;
    }

    string fire(){
      this->output_manager = new OutputManager();
      this->new_post = new NewPost(false);

      return _new_post();
      return "exit";
    }

    string _new_post(){
      string cmd;
      return "";
    }
};

#endif