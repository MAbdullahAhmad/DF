#ifndef LOGIN_PAGE_H
#define LOGIN_PAGE_H

#include "iostream"
#include "../MasterPage.h"

class Login : public MasterPage{
  private:

  public:
    //> Constructors
    Login(){
      this->run();
    }
    Login(bool r){
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
      this->in("Login");
      this->in("__END_CENTER__");
      this->in("__END__");
    }

    void how_to(){
      // Start
      this->in("__START__"); this->in("");

      // Heading
      this->in("Login Form: "); this->in("");

      // Para
      this->in("    Enter your Email and Password in the followings to login to your Account.");
      this->in("    Contact Admin in case you forgot your password.");
      
      this->in("__CENTER__"); this->in("");
      this->in("__END_CENTER__");

      // End
      this->in("__END__");
    }
};

#endif