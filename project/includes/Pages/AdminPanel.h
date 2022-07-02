#ifndef ADMIN_PANEL_PAGE_H
#define ADMIN_PANEL_PAGE_H

#include "iostream"
#include "../Session.h"
#include "../MasterPage.h"

using namespace std;
using namespace SessionSpace;

//> AdminPanel Class
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
      this->topbar();
      this->landing();
      this->how_to();
      this->commands();
      this->footer();
    }

    //> Sections

    // Topbar
    void topbar(){
      // Start
      this->in("__START__"); this->in("");
      
      // Right Content
      this->in("__RIGHT__");
      if(auth()){
        this->in("(" + session->get("_auth_name") + ")");
      } else this->in("");
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

      this->in("Welcome to Admin Portal");
      this->in("-----------------------"); this->in("");
      
      this->in("Welcome to Admin Portal of Distributed Form"); this->in("");
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
      
      this->in("Select an Option from Commands as Follow."); this->in("");

      // End
      this->in("__END__");
    }

    // Commands
    void commands(){
      // Start
      this->in("__START__"); this->in("");
      // Centered Content

      this->in("Commands");
      this->in("--------"); this->in("");
      
      this->in("[U] Manage Users");
      this->in("[C] Manage Channels");
      this->in("[A] Manage Admins"); this->in("");

      // End
      this->in("__END__");
    }

    // Footer
    void footer(){
      // Start
      this->in("__START__"); this->in("");
      
      // Right Content
      this->in("__RIGHT__");
      this->in("[L] Logout  ");
      this->in("__END_RIGHT__");
      
      // Left Content
      this->in("Have a Nice Day");
      this->in("");
      this->in("__END__"); this->in("");

      // Center Content
      this->in("__CENTER__");
      this->in("(c) All Rights Reserved");
      this->in("__END_CENTER__");

      // End
      this->in("__END__");
    }
};

#endif