#ifndef CONTROLLER_SIGNUP_H
#define CONTROLLER_SIGNUP_H

#include "iostream"
#include "../MasterController.h"
#include "../OutputManager.h"
#include "../Pages/Signup.h"
#include "../Models/User.h"

using namespace std;

//> WelcomeController class
class SignupController : public MasterController{
  private:
    OutputManager* output_manager;
    Signup* signup;

  public:
    SignupController(){
      output_manager  = nullptr;
      signup          = nullptr;
    }

    string fire(){
      this->output_manager = new OutputManager();
      this->signup = new Signup(false);

      return _signup();
      return "exit";
    }

    string _signup(){
      string cmd;

      // Props
      string name;
      string nick;
      string username;
      string password;

      // Signup Top
      this->signup->run();
      this->output_manager->execute(this->signup);
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
      ) return "homepage";
      else if ( // Retry
        is_command(cmd, "R")
      ) return "signup";
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
      this->output_manager->feed("Crating Your Account ...");
      this->output_manager->end(); cout << "\n";
      delay_seconds(1);

      // Signup Operation
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
        this->output_manager->feed("Your Account Created Successfully!");
        this->output_manager->end(); cout << "\n";
      }

      // Confirm
      MoveNext:
      this->output_manager->start();
      this->output_manager->feed();
      this->output_manager->feed("Select One");
      this->output_manager->command("__RIGHT__");
      this->output_manager->feed("[L] Login  [B] Back to Homepage");
      this->output_manager->command("__END_RIGHT__");
      this->output_manager->end(); cout << "\n";

      // Command Handeling
      cmd = get_command();
      if ( // Cancel
        is_command(cmd, "L")
      ) return "login";
      else if ( // Retry
        is_command(cmd, "B")
      ) return "homepage";
      else { // Invalid
        cout << "\nInvalid Choice! Retry..\n";
        goto MoveNext;
      }

      return "";
    }
};

#endif