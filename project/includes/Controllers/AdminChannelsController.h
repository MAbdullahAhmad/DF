#ifndef CONTROLLER_ADMIN_CHANNELS_H
#define CONTROLLER_ADMIN_CHANNELS_H

#include "iostream"
#include "../MasterController.h"
#include "../OutputManager.h"
#include "../Pages/AdminChannels.h"
#include "../Models/Channel.h"

using namespace std;

//> WelcomeController class

class AdminChannelsController : public MasterController{
  private:
    OutputManager* output_manager;
    AdminChannels* admin_channels;
    CRUD<Channel>* crud;

  public:
    AdminChannelsController(){
      output_manager  = nullptr;
      admin_channels     = nullptr;
      crud            = nullptr;
    }

    string fire(){
      this->output_manager = new OutputManager();
      this->admin_channels = new AdminChannels();
      this->crud = new CRUD<Channel>("channels");

      return _admin_channels();
      return "exit";
    }

    string _admin_channels(){
      string cmd;

      // Execute Page
      this->admin_channels->display_channels(this->crud->all());
      this->admin_channels->del_channel();
      this->admin_channels->footer();
      this->output_manager->execute(this->admin_channels);

      // Move Next
      MoveNext:

      // Command Handeling
      cmd = get_command();
      if ( // Cancel
        is_command(cmd, "L")
      ) return "logout";
      else if ( // Retry
        is_command(cmd, "B")
      ) return "admin_panel";
      else if ( // Retry
        is_command(cmd, "C")
      ) return "admin_create_channel";
      else if ( // Retry
        is_command(cmd, "D")
      ) true;
      else { // Invalid
        cout << "\nInvalid Choice! Retry..\n";
        goto MoveNext;
      }

      // Move Next
      DeleteChannel:

      // Cancel
      this->output_manager->start();
      this->output_manager->feed();
      this->output_manager->feed("Delete a Channel");
      this->output_manager->command("__RIGHT__");
      this->output_manager->feed("[C] Cancel");
      this->output_manager->command("__END_RIGHT__");

      // Input ID
      this->output_manager->feed("Select ID of Channel from Above and Enter in Following: ");
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
      ) return "admin_channels";
      
      // Deletion Operation
      Channel* u = crud->read(stoi(cmd));
      if(u){
        if(crud->del(stoi(cmd))){
          this->output_manager->start();
          this->output_manager->feed();
          this->output_manager->feed("Channel Deleted Successfully ...");
          this->output_manager->end(); cout << "\n";
          delay_seconds(1);
          return "admin_channels";
        } else {
          cout << "Unable to Delete Channel !";
          goto DeleteChannel;
        }
      } else {
        cout << "Channel Not Found !";
        goto DeleteChannel;
      }

      return "";
    }
};

#endif