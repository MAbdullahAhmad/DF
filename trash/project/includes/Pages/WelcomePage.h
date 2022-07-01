#ifndef WELCOME_PAGE_H
#define WELCOME_PAGE_H

#include "iostream"
#include "../MasterPage.h"

class WelcomePage : public MasterPage{
  private:

  public:
    //> Constructors
    WelcomePage(){
      this->run();
    }
    WelcomePage(bool r){
      if(r) this->run();
    }

    // Run Welcome Page
    void run(){
      this->landing();
      this->how_to();
    }

    //> Sections

    // Landing
    void landing(){
      // Start
      this->in("__START__"); this->in("");
      // Centered Content
      this->in("__CENTER__");

      this->in("Welcome to DF");
      this->in("-------------"); this->in("");
      
      this->in("Welcome to Distributed Form"); this->in("");
      this->in("<->"); this->in("");
      this->in("__END_CENTER__");

      // End
      this->in("__END__");
    }

    // How To
    void how_to(){
      // Start
      this->in("__START__"); this->in("");
      // Centered Content

      this->in("How To");
      this->in("------"); this->in("");
      
      this->in("Lorem ipsum dollar sit emut dip."); this->in("");

      // End
      this->in("__END__");
    }
};

#endif