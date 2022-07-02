#ifndef CONTROLLER_ADMIN_CREATE_USER_H
#define CONTROLLER_ADMIN_CREATE_USER_H

#include "iostream"
#include "../MasterController.h"
#include "../OutputManager.h"
#include "../Pages/AdminCreateUser.h"
#include "../Models/User.h"

using namespace std;

//> WelcomeController class
class AdminCreateUserController : public MasterController{
  private:
    OutputManager* output_manager;
    AdminCreateUser* admin_create_user;

  public:
    AdminCreateUserController(){
      output_manager  = nullptr;
      admin_create_user          = nullptr;
    }

    string fire(){
      this->output_manager = new OutputManager();
      this->admin_create_user = new AdminCreateUser(false);

      return _admin_create_user();
      return "exit";
    }

    string _admin_create_user(){
      string cmd;

      // Props
      string name;
      string nick;
      string username;
      string password;

      // AdminCreateUser Top
      this->admin_create_user->run();
      this->output_manager->execute(this->admin_create_user);
      cout << "\n";
      
      // Input Username
      this->output_manager->get_bm()->upload(); cout << '\n';
      this->output_manager->get_bm()->upload();
      cout << "\t\tEnter Complete Name: "; name = getline();

      // Input Username
      this->output_manager->get_bm()->upload();
      cout << "\t\tEnter Nick Name:     "; nick = getline();

      // Input Username
      this->output_manager->get_bm()->upload();
      cout << "\t\tEnter Username:      "; username = getline();

      // Input Password
      this->output_manager->get_bm()->upload();
      cout << "\t\tEnter Password:      "; password = getline();
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
      ) return "admin_users";
      else if ( // Retry
        is_command(cmd, "R")
      ) return "admin_create_user";
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
      this->output_manager->feed("Creating New User ...");
      this->output_manager->end(); cout << "\n";
      delay_seconds(1);

      // AdminCreateUser Operation
      User * user;
      user = new User(
        nick.c_str(),
        name.c_str(),
        username.c_str(),
        password.c_str(),
        'u'
      );
      if(user->create()){
        // Authenticating Message
        this->output_manager->start();
        this->output_manager->feed();
        this->output_manager->feed("User Created Successfully!");
        this->output_manager->end(); cout << "\n";
      }

      // Move Next
      MoveNext:
      this->output_manager->start();
      this->output_manager->feed();
      this->output_manager->feed("Select One");
      this->output_manager->command("__RIGHT__");
      this->output_manager->feed("[C] Create Another  [B] Back to Users");
      this->output_manager->command("__END_RIGHT__");
      this->output_manager->end(); cout << "\n";

      // Command Handeling
      cmd = get_command();
      if ( // Cancel
        is_command(cmd, "C")
      ) return "admin_create_user";
      else if ( // Retry
        is_command(cmd, "B")
      ) return "admin_users";
      else { // Invalid
        cout << "\nInvalid Choice! Retry..\n";
        goto MoveNext;
      }

      return "";
    }
};

#endif