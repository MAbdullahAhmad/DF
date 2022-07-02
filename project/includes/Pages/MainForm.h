#ifndef MAIN_FORM_PAGE_H
#define MAIN_FORM_PAGE_H

#include "iostream"
#include "../MasterPage.h"

class MainForm : public MasterPage{
  private:

  public:
    //> Constructors
    MainForm(){
      this->run();
    }
    MainForm(bool r){
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
      this->in("MainForm");
      this->in("__END_CENTER__");
      this->in("__END__");
    }

    void how_to(){
      // Start
      this->in("__START__"); this->in("");

      // Heading
      this->in("MainForm Form: "); this->in("");

      // Para
      this->in("    Fill up following form to create your account");
      this->in("    You'll confirm before submission");
      
      this->in("__CENTER__"); this->in("");
      this->in("__END_CENTER__");

      // End
      this->in("__END__");
    }
};

#endif