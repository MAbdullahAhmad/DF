#ifndef ABOUT_PAGE_H
#define ABOUT_PAGE_H

#include "iostream"
#include "../MasterPage.h"

class About : public MasterPage{
  private:

  public:
    //> Constructors
    About(){
      this->run();
    }
    About(bool r){
      if(r) this->run();
    }

    // Run Welcome Page
    void run(){
      this->topbar();
      this->about();
      this->footer();
    }

    // Topbar
    void topbar(){
      // Start
      this->in("__START__"); this->in("");
      
      // Right Content
      this->in("[B] Back to Homepage");

      // End
      this->in("__END__");
    }

    //> Sections
    void about(){
      this->in("__START__");
      this->in("");
      this->in("About Us");
      this->in("");
      this->in("Some People with a Little knowledge and great passion tried to create something different :). Designed and Developed by a Team:");
      this->in("");
      this->in("   - Abdullah Ahmad");
      this->in("   - Ahmad Raza Attari");
      this->in("   - Ahmad Manzoor Choudnary");
      this->in("");
    }


    // Footer
    void footer(){
      // Start
      this->in("__START__"); this->in("");
      
      // Left Content
      this->in("Have a Nice Day");
      
      // Center Content
      this->in(""); this->in("__END__"); this->in("");
      this->in("__CENTER__");
      this->in("(c) All Rights Reserved");
      this->in("__END_CENTER__");

      // End
      this->in("__END__");
    }
};

#endif