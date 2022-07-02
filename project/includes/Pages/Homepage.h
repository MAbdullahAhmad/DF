#ifndef WELCOME_PAGE_H
#define WELCOME_PAGE_H

#include "iostream"
#include "../MasterPage.h"

class Homepage : public MasterPage{
  private:

  public:
    //> Constructors
    Homepage(){
      this->run();
    }
    Homepage(bool r){
      if(r) this->run();
    }

    // Run Welcome Page
    void run(){
      this->topbar();
      this->landing();
      this->how_to();
      this->footer();
    }

    //> Sections

    // Topbar
    void topbar(){
      // Start
      this->in("__START__"); this->in("");
      
      // Right Content
      this->in("__RIGHT__");
      this->in("[L] Login  |  [S] Sign-Up");
      this->in("__END_RIGHT__");

      // End
      this->in("__END__");
    }

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

    // Footer
    void footer(){
      // Start
      this->in("__START__"); this->in("");
      
      // Right Content
      this->in("__RIGHT__");
      this->in("[A] About Us  ");
      this->in("[C] Contact Us");
      this->in("__END_RIGHT__");
      
      // Left Content
      this->in("Have a Nice Day");
      this->in("");
      this->in("Alpha Beta Gama Theta. Eta Peta Meta Geta");
      this->in("Classification means to Seperate sort out");
      this->in("same and different thigs or objects on");
      this->in("the basis of structure and their functional");
      this->in("units.");
      
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