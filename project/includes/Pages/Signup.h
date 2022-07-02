#ifndef SIGNUP_PAGE_H
#define SIGNUP_PAGE_H

#include "iostream"
#include "../MasterPage.h"

class Signup : public MasterPage{
  private:

  public:
    //> Constructors
    Signup(){
      this->run();
    }
    Signup(bool r){
      if(r) this->run();
    }

    // Run Welcome Page
    void run(){
      this->header();
      this->signup_form();
    }

    //> Sections
    void header(){
      this->in("__START__");
      this->in("__CENTER__");
      this->in("");
      this->in("Signup");
      //this->in("");
      this->in("__END_CENTER__");
      this->in("__END__");


      this->in("__START__");
      this->in("Heading: ");
      this->in("");
      this->in("Paragraph here.");
      this->in("__END__");
    }

    void signup_form(){

    }
};

#endif