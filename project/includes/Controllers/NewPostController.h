#ifndef CONTROLLER_NEW_POST_H
#define CONTROLLER_NEW_POST_H

#include "iostream"
#include "cstring"
#include "../MasterController.h"
#include "../OutputManager.h"
#include "../Pages/NewPost.h"
#include "../Models/Post.h"

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
      this->new_post = new NewPost();

      return _new_post();
      return "exit";
    }

    string _new_post(){
      string cmd;

      // Props
      string title;
      string content;

      // NewPost Top
      this->output_manager->execute(this->new_post);
      cout << "\n";
      
      // Input Title
      this->output_manager->get_bm()->upload(); cout << '\n';
      this->output_manager->get_bm()->upload();
      cout << "\t\tEnter Title:    "; title = getline();

      // Input Post Content
      this->output_manager->get_bm()->upload();
      cout << "\t\tEnter Post:     "; content = getline();

      // Confirm
      ConfirmDetails:
      this->output_manager->start();
      this->output_manager->feed();
      this->output_manager->feed("Is Above Information Correct ?");
      this->output_manager->command("__RIGHT__");
      this->output_manager->feed("[Y] Yes  [C] Cancel  [R] Retry");
      this->output_manager->command("__END_RIGHT__");
      this->output_manager->end(); cout << "\n";

      // Command Handeling
      cmd = get_command();
      if ( // Cancel
        is_command(cmd, "C")
      ) return "channels";
      else if ( // Retry
        is_command(cmd, "R")
      ) return "new_post";
      else if ( // Yes
        is_command(cmd, "Y")
      ) true;
      else { // Invalid
        cout << "\nInvalid Choice! Retry..\n";
        goto ConfirmDetails;
      }

      // Authenticating Message
      this->output_manager->start();
      this->output_manager->feed();
      this->output_manager->feed("Posting ...");
      this->output_manager->end(); cout << "\n";
      // delay_seconds(1); //@debug

      // NewPost Operation
      Post * post;
      post = new Post(
        stoi(session->get("channel_id")),
        stoi(session->get("_auth_id")),
        title.c_str(),
        content.c_str()
      );
      if(post->create()){
        // Authenticating Message
        this->output_manager->start();
        this->output_manager->feed();
        this->output_manager->feed("Your Post is Flying over the system!");
        this->output_manager->end(); cout << "\n";
        delay_seconds(1);
      } else {
        cout << "NIAOUW\n";
        delay_seconds(1);
      }

      return "channels";
    }
};

#endif