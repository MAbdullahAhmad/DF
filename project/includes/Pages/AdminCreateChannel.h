#ifndef ADMIN_CREATE_CHANNEL_PAGE_H
#define ADMIN_CREATE_CHANNEL_PAGE_H

#include "iostream"
#include "../MasterPage.h"

class AdminCreateChannel : public MasterPage{
  private:

  public:
    //> Constructors
    AdminCreateChannel(){
      this->run();
    }
    AdminCreateChannel(bool r){
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
      this->in("Create New Channel");
      this->in("__END_CENTER__");
      this->in("__END__");
    }

    void how_to(){
      // Start
      this->in("__START__"); this->in("");

      // Heading
      this->in("Create New Channel Form: "); this->in("");

      // Para
      this->in("    Fill up following form to create new channel account");
      this->in("    You'll confirm before submission");
      
      this->in("__CENTER__"); this->in("");
      this->in("__END_CENTER__");

      // End
      this->in("__END__");
    }
};

#endif