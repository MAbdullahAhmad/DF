#ifndef ADMIN_PANEL_PAGE_H
#define ADMIN_PANEL_PAGE_H

#include "iostream"
#include "../MasterPage.h"

class AdminPanel : public MasterPage{
  private:

  public:
    //> Constructors
    AdminPanel(){
      this->run();
    }
    AdminPanel(bool r){
      if(r) this->run();
    }

    // Run Welcome Page
    void run(){
      this->header();
    }

    //> Sections
    void header(){
      this->in("__START__");
      this->in("");
      this->in("Hello");
      this->in("`````");


      this->in("__CENTER__");
      this->in("abc");
      this->in("__END_CENTER__");
      this->in("__END__");
    }
};

#endif