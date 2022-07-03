#ifndef CONTROLLER_MAIN_FORM_H
#define CONTROLLER_MAIN_FORM_H

#include "iostream"
#include "../../libs/string_lib.h"
#include "../MasterController.h"
#include "../OutputManager.h"
#include "../Pages/MainForm.h"
#include "../Models/User.h"

using namespace std;

//> WelcomeController class
class MainFormController : public MasterController{
  private:
    OutputManager* output_manager;
    MainForm* main_form;
    CRUD<Channel>* crud;

  public:
    MainFormController(){
      output_manager  = nullptr;
      main_form       = nullptr;
      crud            = nullptr;
    }

    string fire(){
      this->output_manager = new OutputManager();
      this->main_form = new MainForm(false);
      this->crud = new CRUD<Channel>("channels");

      return _main_form();
      return "exit";
    }

    string _main_form(){
      string cmd;

      this->main_form->display_channels(this->crud->all());
      this->main_form->select_channel();
      this->main_form->footer();
      this->output_manager->execute(this->main_form);

      // Move Next
      MoveNext:

      // Command Handeling
      cmd = get_command();
      if ( // Cancel
        is_command(cmd, "L")
      ) return "logout";
      else if ( // Retry
        is_command(cmd, "S")
      ) true;
      else { // Invalid
        cout << "\nInvalid Choice! Retry..\n";
        goto MoveNext;
      }

      // Move Next
      SelectChannel:

      // Cancel
      this->output_manager->start();
      this->output_manager->feed();
      this->output_manager->feed("Select a Channel");
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
      ) return "main_form";
      if ( // Cancel
        is_command(cmd, "L")
      ) return "logout";
      
      // Selection Operation
      Channel* u = crud->read(stoi(cmd));
      if(u){
        session->put("channel_id", str(u->get_id()));
      } else {
        this->output_manager->get_bm()->upload();
        cout << "Channel Not Found !\n";
        goto SelectChannel;
      }

      return "channels";
    }
};

#endif