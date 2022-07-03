#ifndef CONTROLLER_CHANNELS_H
#define CONTROLLER_CHANNELS_H

#include "iostream"
#include "../CRUD.h"
#include "../MasterController.h"
#include "../OutputManager.h"
#include "../Pages/Channels.h"
#include "../Models/Channel.h"
#include "../Session.h"

using namespace std;
using namespace SessionSpace;

//> WelcomeController class
class ChannelsController : public MasterController{
  private:
    OutputManager* output_manager;
    Channels* channels;
    CRUD<Post>* crud;

  public:
    ChannelsController(){
      output_manager  = nullptr;
      channels        = nullptr;
      crud            = nullptr;
    }

    string fire(){
      this->output_manager = new OutputManager();
      this->channels = new Channels();
      this->crud = new CRUD<Post>("posts");

      return _channels();
      return "exit";
    }

    string _channels(){
      string cmd;

      // Execute Page
      Channel * channel;
      channel = new Channel();
      channel->set_id(stoi(session->get("channel_id")));
      channel->crud()->read();

      this->channels->landing(channel->get_title());
      this->channels->create_post();
      this->channels->display_posts(this->crud->all(), stoi(session->get("channel_id")));
      this->channels->select_post();
      this->channels->footer();
      this->output_manager->execute(this->channels);


      // Move Next
      MoveNext:

      // Command Handeling
      cmd = get_command();
      if ( // Cancel
        is_command(cmd, "L")
      ) return "logout";
      else if ( // Retry
        is_command(cmd, "C")
      ) return "create_post";
      else if ( // Cancel
        is_command(cmd, "B")
      ) return "main_form";
      else if ( // Retry
        is_command(cmd, "S")
      ) true;
      else { // Invalid
        cout << "\nInvalid Choice! Retry..\n";
        goto MoveNext;
      }

      // Move Next
      SelectPost:

      // Cancel
      this->output_manager->start();
      this->output_manager->feed();
      this->output_manager->feed("Select a Post");
      this->output_manager->command("__RIGHT__");
      this->output_manager->feed("[C] Cancel");
      this->output_manager->command("__END_RIGHT__");

      // Input ID
      this->output_manager->feed("Select ID of Post from Above and Enter in Following: ");
      this->output_manager->feed("");
      this->output_manager->end();
      this->output_manager->get_bm()->upload(); cout << '\n';
      this->output_manager->get_bm()->upload();
      cout << "Enter ID: ";
      cmd = getline();
      this->output_manager->get_bm()->upload(); cout << '\n';
      
      // #nd

      // Command Handeling
      if ( // Cancel
        is_command(cmd, "C")
      ) return "channels";
      else if ( // Cancel
        is_command(cmd, "L")
      ) return "logout";
      
      // Selection Operation
      Post* p = crud->read(stoi(cmd));
      if(p){
        session->put("post_id", str(p->get_id()));
      } else {
        this->output_manager->get_bm()->upload();
        cout << "Post Not Found !\n";
        goto SelectPost;
      }

      return "view_post";
    }
};

#endif