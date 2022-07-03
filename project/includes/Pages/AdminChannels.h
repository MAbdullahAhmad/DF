#ifndef ADMIN_CHANNELS_PAGE_H
#define ADMIN_CHANNELS_PAGE_H

#include "iostream"
#include "../MasterPage.h"
#include "../Models/Channel.h"

class AdminChannels : public MasterPage{
  private:

  public:
    //> Constructors
    AdminChannels(){
      this->run();
    }
    AdminChannels(bool r){
      if(r) this->run();
    }

    // Run Welcome Page
    void run(){
      this->topbar();
      this->little_desc();
      this->new_channel();
    }
    
    // Topbar
    void topbar(){
      // Start
      this->in("__START__"); this->in("");
      
      // Right Content
      this->in("[B] Back to Portal");

      // End
      this->in("__END__");
    }

    //> Sections
    void little_desc(){
      this->in("__START__");
      this->in("");
      this->in("Manage Channels"); this->in("");
      this->in("You can Manager your Channels here.");
      this->in("");
      this->in("__END__");
    }

    void new_channel(){
      this->in("__START__");
      this->in("");
      this->in("Create Channel"); this->in("");
      this->in("[C] Create a New Channel.");
      this->in("");
      this->in("__END__");
    }

    void del_channel(){
      this->in("__START__");
      this->in("");
      this->in("Delete Channel"); this->in("");
      this->in("[D] Delete a Channel.");
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
      this->in("ALL USERS");
      this->in("---------");
      this->in("Channels are as follow:");
      this->in("__END__");
      for(Channel c : channels){
        c.display(this);
      }
    }
};

#endif