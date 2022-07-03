#ifndef NEW_POST_PAGE_H
#define NEW_POST_PAGE_H

#include "iostream"
#include "../MasterPage.h"

class NewPost : public MasterPage{
  private:

  public:
    //> Constructors
    NewPost(){
      this->run();
    }
    NewPost(bool r){
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
      this->in("New Post");
      this->in("__END_CENTER__");
      this->in("__END__");
    }

    void how_to(){
      // Start
      this->in("__START__"); this->in("");

      // Heading
      this->in("Create New Post: "); this->in("");

      // Parar
      this->in("    Create Your New Post In Folowings");
      this->in("    You'll confirm before submission");
      
      this->in("__CENTER__"); this->in("");
      this->in("__END_CENTER__");

      // End
      this->in("__END__");
    }
};

#endif