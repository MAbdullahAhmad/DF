#ifndef CONTROLLER_VIEW_POST_H
#define CONTROLLER_VIEW_POST_H

#include "iostream"
#include "../MasterController.h"
#include "../OutputManager.h"
#include "../Pages/ViewPost.h"
#include "../Models/User.h"

using namespace std;

//> WelcomeController class
class ViewPostController : public MasterController{
  private:
    OutputManager* output_manager;
    ViewPost* view_post;

  public:
    ViewPostController(){
      output_manager  = nullptr;
      view_post          = nullptr;
    }

    string fire(){
      this->output_manager = new OutputManager();
      this->view_post = new ViewPost(false);

      return _view_post();
      return "exit";
    }

    string _view_post(){
      string cmd;
      return "";
    }
};

#endif