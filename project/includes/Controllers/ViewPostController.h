#ifndef CONTROLLER_VIEW_POST_H
#define CONTROLLER_VIEW_POST_H

#include "iostream"
#include "cstring"
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
      view_post       = nullptr;
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
      this->view_post->post_comments((new PostComment())->crud()->all(), stoi(session->get("post_id")));
      this->output_manager->execute(this->view_post);

      // Move Next
      MoveNext:

      // Command Handeling
      cmd = get_command();
      if ( // Cancel
        is_command(cmd, "B")
      ) return "channels";
      else if ( // Cancel
        is_command(cmd, "C")
      ) true;
      else { // Invalid
        cout << "\nInvalid Choice! Retry..\n";
        goto MoveNext;
      }

      // New Comment
      NewComment:

      // Cancel
      this->output_manager->start();
      this->output_manager->feed();
      this->output_manager->feed("Write New Comment");
      this->output_manager->command("__RIGHT__");
      this->output_manager->feed("[C] Cancel");
      this->output_manager->command("__END_RIGHT__");

      // Input ID
      this->output_manager->feed("Enter Your Comment in Following: ");
      this->output_manager->feed("");
      this->output_manager->end();
      this->output_manager->get_bm()->upload(); cout << '\n';
      this->output_manager->get_bm()->upload();
      cout << "Comment: ";
      cmd = getline();
      this->output_manager->get_bm()->upload(); cout << '\n';
      
      // Command Handeling
      if ( // Cancel
        is_command(cmd, "C")
      ) return "view_post";
      else if ( // Cancel
        is_command(cmd, "B")
      ) return "channels";
      
      // Input Comment
      PostComment* pc = new PostComment();
      pc->set_post_id(stoi(session->get("post_id")));
      pc->set_user_id(stoi(session->get("_auth_id")));
      pc->set_comment(cmd.c_str());

      if(pc->create()){
        // Authenticating Message
        this->output_manager->start();
        this->output_manager->feed();
        this->output_manager->feed("Commented Successfully!");
        this->output_manager->end(); cout << "\n";
        delay_seconds(1);
      } else {
        this->output_manager->get_bm()->upload();
        cout << "Unable to Comment !\n";
        delay_seconds(1);
      }

      return "view_post";
    }
};

#endif