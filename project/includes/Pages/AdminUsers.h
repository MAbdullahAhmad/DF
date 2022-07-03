#ifndef ADMIN_USERS_PAGE_H
#define ADMIN_USERS_PAGE_H

#include "iostream"
#include "vector"
#include "../MasterPage.h"
#include "../Models/User.h"

class AdminUsers : public MasterPage{
  private:

  public:
    //> Constructors
    AdminUsers(){
      this->run();
    }
    AdminUsers(bool r){
      if(r) this->run();
    }

    // Run Welcome Page
    void run(){
      this->topbar();
      this->little_desc();
      this->new_user();
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
      this->in("Manage Users"); this->in("");
      this->in("You can Manager your Users here.");
      this->in("");
      this->in("__END__");
    }

    void new_user(){
      this->in("__START__");
      this->in("");
      this->in("Create User"); this->in("");
      this->in("[C] Create a New User.");
      this->in("");
      this->in("__END__");
    }

    void display_users(vector<User> users){
      this->in("__START__");
      this->in("");
      this->in("ALL USERS");
      this->in("---------");
      this->in("Users are as follow:");
      this->in("__END__");
      for(User u : users){
        if(u.get_role()=='a') continue;
        u.display(this);
      }
    }

    void del_user(){
      this->in("__START__");
      this->in("");
      this->in("Delete User"); this->in("");
      this->in("[D] Delete a User.");
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
};

#endif