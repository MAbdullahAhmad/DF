#ifndef ADMIN_CREATE_USER_PAGE_H
#define ADMIN_CREATE_USER_PAGE_H

#include "iostream"
#include "../MasterPage.h"

class AdminCreateUser : public MasterPage{
  private:

  public:
    //> Constructors
    AdminCreateUser(){
      this->run();
    }
    AdminCreateUser(bool r){
      if(r) this->run();
    }

    // Run Welcome Page
    void run(){
      this->header();
      this->how_to();
    }

    //> Sections
    void header(){
      // Header
      this->in("__START__"); this->in("");
      this->in("__CENTER__"); 
      this->in("Create New User");
      this->in("__END_CENTER__");
      this->in("__END__");
    }

    void how_to(){
      // Start
      this->in("__START__"); this->in("");

      // Heading
      this->in("Create New User Form: "); this->in("");

      // Para
      this->in("    Fill up following form to create new user account");
      this->in("    You'll confirm before submission");
      
      this->in("__CENTER__"); this->in("");
      this->in("__END_CENTER__");

      // End
      this->in("__END__");
    }
};

#endif