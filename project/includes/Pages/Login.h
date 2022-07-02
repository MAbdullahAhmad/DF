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
      this->login_form();
    }

    //> Sections
    void header(){
      this->in("__START__");
      this->in("__CENTER__");
      this->in("");
      this->in("Login");
      //this->in("");
      this->in("__END_CENTER__");
      this->in("__END__");


      this->in("__START__");
      this->in("Heading: ");
      this->in("");
      this->in("Paragraph here.");
      this->in("__END__");
      
      
    }

    void login_form(){

    }
};

#endif