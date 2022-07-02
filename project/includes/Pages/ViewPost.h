#ifndef VIEW_POST_PAGE_H
#define VIEW_POST_PAGE_H

#include "iostream"
#include "../MasterPage.h"

class ViewPost : public MasterPage{
  private:

  public:
    //> Constructors
    ViewPost(){
      this->run();
    }
    ViewPost(bool r){
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