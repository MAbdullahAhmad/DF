#ifndef CONTROLLER_ADMIN_CREATE_CHANNEL_H
#define CONTROLLER_ADMIN_CREATE_CHANNEL_H

#include "iostream"
#include "../MasterController.h"
#include "../OutputManager.h"
#include "../Pages/AdminCreateChannel.h"
#include "../Models/Channel.h"

using namespace std;

//> WelcomeController class
class AdminCreateChannelController : public MasterController{
  private:
    OutputManager* output_manager;
    AdminCreateChannel* admin_create_channel;

  public:
    AdminCreateChannelController(){
      output_manager                = nullptr;
      admin_create_channel          = nullptr;
    }

    string fire(){
      this->output_manager = new OutputManager();
      this->admin_create_channel = new AdminCreateChannel(false);

      return _admin_create_channel();
      return "exit";
    }

    string _admin_create_channel(){
      string cmd;

      // Props
      int server_id = 1;
      string title;

      // AdminCreateChannel Top
      this->admin_create_channel->run();
      this->output_manager->execute(this->admin_create_channel);
      cout << "\n";
      
      // Input Channel Title
      this->output_manager->get_bm()->upload(); cout << '\n';
      this->output_manager->get_bm()->upload();
      cout << "\t\tEnter Title: "; title = getline();
      this->output_manager->get_bm()->upload(); cout << "\n\n";

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
      ) return "admin_channels";
      else if ( // Retry
        is_command(cmd, "R")
      ) return "admin_create_channel";
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
      this->output_manager->feed("Creating New Channel ...");
      this->output_manager->end(); cout << "\n";
      // delay_seconds(1);

      // AdminCreateChannel Operation
      cout << "Pinda\n";
      Channel * channel;
      cout << "Minda\n";
      channel = new Channel(
        server_id,
        title.c_str(),
        2
      );
      cout << "Jinda\n";
      if(channel->create()){
        // Authenticating Message
        this->output_manager->start();
        this->output_manager->feed();
        this->output_manager->feed("Channel Created Successfully!");
        this->output_manager->end(); cout << "\n";
      }

      // Move Next
      MoveNext:
      this->output_manager->start();
      this->output_manager->feed();
      this->output_manager->feed("Select One");
      this->output_manager->command("__RIGHT__");
      this->output_manager->feed("[C] Create Another  [B] Back to Channels");
      this->output_manager->command("__END_RIGHT__");
      this->output_manager->end(); cout << "\n";

      // Command Handeling
      cmd = get_command();
      if ( // Cancel
        is_command(cmd, "C")
      ) return "admin_create_channel";
      else if ( // Retry
        is_command(cmd, "B")
      ) return "admin_channels";
      else { // Invalid
        cout << "\nInvalid Choice! Retry..\n";
        goto MoveNext;
      }

      return "";
    }
};

#endif