#ifndef MAIN_FORM_PAGE_H
#define MAIN_FORM_PAGE_H

#include "iostream"
#include "../MasterPage.h"
#include "../Models/Channel.h"
#include "../Session.h"

using namespace std;
using namespace SessionSpace;

class MainForm : public MasterPage{
  private:

  public:
    //> Constructors
    MainForm(){
      this->run();
    }
    MainForm(bool r){
      if(r) this->run();
    }

    // Run Welcome Page
    void run(){
      this->topbar();
      this->landing();
      this->little_desc();
    }
    
    //> Sections

    // Topbar
    void topbar(){
      // Start
      this->in("__START__"); this->in("");
      
      // Right Content (Name)
      this->in("__RIGHT__");
      this->in("| " + session->get("_auth_name") + "  ");
      this->in("__END_RIGHT__");

      // End
      this->in("__END__");
    }

    // Landing
    void landing(){
      // Start
      this->in("__START__"); this->in("");
      // Centered Content
      this->in("__CENTER__");

      this->in("Main Form");
      this->in("-------------"); this->in("");
      
      this->in("Welcome to Main Form"); this->in("");
      this->in("Select a Channel from Followings to Browse Posts"); this->in("");
      this->in("<->"); this->in("");
      this->in("__END_CENTER__");

      // End
      this->in("__END__");
    }

    //> Sections
    void little_desc(){
      this->in("__START__");
      this->in("");
      this->in("Browse Channels"); this->in("");
      this->in("You can Browse and Select a channel in followings.");
      this->in("");
      this->in("__END__");
    }

    // Footer
    void footer(){
      // Start
      this->in("__START__"); this->in("");
      
      // Right Content
      this->in("__RIGHT__");
      this->in("[L] Logout  ");
      this->in("__END_RIGHT__");
      
      // Left Content
      this->in("Have a Nice Day");
      
      // Center Content
      this->in(""); this->in("__END__"); this->in("");
      this->in("__CENTER__");
      this->in("(c) All Rights Reserved");
      this->in("__END_CENTER__");

      // End
      this->in("__END__");
    }

    void display_channels(vector<Channel> channels){
      this->in("__START__");
      this->in("");
      this->in("ALL Channels");
      this->in("---------");
      this->in("Channels are as follow:");
      this->in("__END__");
      for(Channel c : channels){
        c.row_display(this);
      }
    }

    void select_channel(){
      this->in("__START__");
      this->in("");
      this->in("Select a Channel");
      this->in("__RIGHT__");
      this->in("[S] Select a Channel");
      this->in("__END_RIGHT__");
      this->in("__END__");
    }
};

#endif