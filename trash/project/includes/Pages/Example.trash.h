#ifndef WELCOME_PAGE_H
#define WELCOME_PAGE_H

#include "iostream"
#include "../MasterPage.h"

class About : public MasterPage{
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
    }

    //> Sections
    
};

#endif