#ifndef CONTROLLER_HOMEPAGE_H
#define CONTROLLER_HOMEPAGE_H

#include "iostream"
#include "../../libs/io.h"
#include "../../libs/mvc.h"
#include "../MasterController.h"
#include "../OutputManager.h"
#include "../Pages/Homepage.h"

#include "../Services/PopupService.h"

using namespace std;

//> WelcomeController class
class HomepageController : public MasterController{
  private:
    OutputManager* output_manager;
    Homepage* homepage;

  public:
    HomepageController(){
      output_manager  = nullptr;
      homepage        = nullptr;
    }

    string fire(){
      this->output_manager = new OutputManager();
      this->homepage = new Homepage(false);

      return _homepage();
      return "exit";
    }

    string _homepage(){
      string command;

      // Menu Loop
      while(command != "exit"){
        // Display Homepage
        this->homepage->run();
        this->output_manager->execute(this->homepage);
        // PopupService* ps;

        // Command Handeling
        command = get_command();
        /**/ if (is_command("L", command))  return "login";
        else if (is_command("S", command))  return "signup";
        else if (is_command("A", command))  return "about_us";
        else if (is_command("C", command))  return "contact_us";
        else if (is_command("E", command))  return "exit";
        else                                new PopupService ("Invalid Input", "You Entered Wrong Input. Please Try Again Later.");
      }

      return "";
    }
};

#endif