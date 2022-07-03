#ifndef CONTROLLER_VIEW_POST_H
#define CONTROLLER_VIEW_POST_H

#include "iostream"
#include "../MasterController.h"
#include "../OutputManager.h"
#include "../Pages/ViewPost.h"
#include "../Models/Post.h"
#include "../Session.h"

using namespace std;
using namespace SessionSpace;

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
      this->view_post = new ViewPost();

      return _view_post();
      return "exit";
    }

    string _view_post(){
      string cmd;
      Post* post = (new Post())->crud()->read(stoi(session->get("post_id")));
      
      this->view_post->post_header(post->get_title(), post->author()->get_name());
      this->view_post->post_content(post->get_content());
      this->output_manager->execute(this->view_post);

      // Move Next
      MoveNext:

      // Command Handeling
      cmd = get_command();
      if ( // Cancel
        is_command(cmd, "B")
      ) return "channels";
      else { // Invalid
        cout << "\nInvalid Choice! Retry..\n";
        goto MoveNext;
      }

      return "";
    }
};

#endif