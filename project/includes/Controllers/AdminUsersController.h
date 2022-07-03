#ifndef CONTROLLER_ADMIN_USERS_H
#define CONTROLLER_ADMIN_USERS_H

#include "iostream"
#include "string"
#include "../CRUD.h"
#include "../MasterController.h"
#include "../OutputManager.h"
#include "../Pages/AdminUsers.h"
#include "../Models/User.h"

using namespace std;

//> WelcomeController class
class AdminUsersController : public MasterController{
  private:
    OutputManager* output_manager;
    AdminUsers* admin_users;
    CRUD<User>* crud;

  public:
    AdminUsersController(){
      output_manager  = nullptr;
      admin_users     = nullptr;
      crud            = nullptr;
    }

    string fire(){
      this->output_manager = new OutputManager();
      this->admin_users = new AdminUsers();
      this->crud = new CRUD<User>("users");

      return _admin_users();
      return "exit";
    }

    string _admin_users(){
      string cmd;

      // Execute Page
      this->admin_users->display_users(this->crud->all());
      this->admin_users->del_user();
      this->admin_users->footer();
      this->output_manager->execute(this->admin_users);

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
      ) return "admin_create_user";
      else if ( // Retry
        is_command(cmd, "D")
      ) true;
      else { // Invalid
        cout << "\nInvalid Choice! Retry..\n";
        goto MoveNext;
      }

      // Move Next
      DeleteUser:

      // Cancel
      this->output_manager->start();
      this->output_manager->feed();
      this->output_manager->feed("Delete a User");
      this->output_manager->command("__RIGHT__");
      this->output_manager->feed("[C] Cancel");
      this->output_manager->command("__END_RIGHT__");

      // Input ID
      this->output_manager->feed("Select ID of User from Above and Enter in Following: ");
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
      ) return "admin_users";
      
      // Deletion Operation
      User* u = crud->read(stoi(cmd));
      if(u){
        if(crud->del(stoi(cmd))){
          this->output_manager->start();
          this->output_manager->feed();
          this->output_manager->feed("User Deleted Successfully ...");
          this->output_manager->end(); cout << "\n";
          delay_seconds(1);
          return "admin_users";
        } else {
          cout << "Unable to Delete User !";
          goto DeleteUser;
        }
      } else {
        cout << "User Not Found !";
        goto DeleteUser;
      }

      return "";
    }
};

#endif