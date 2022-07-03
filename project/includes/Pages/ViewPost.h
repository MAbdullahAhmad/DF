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
      this->topbar();
    }

    // Topbar
    void topbar(){
      // Start
      this->in("__START__"); this->in("");
      
      // Right Content
      this->in("__RIGHT__");
      this->in("[B] Back to Posts");
      this->in("__END_RIGHT__");

      // End
      this->in("__END__");
    }

    // Landing
    void post_header(string post_title, string author_name){
      // Start
      this->in("__START__"); this->in("");
      // Centered Content
      this->in("__CENTER__");

      this->in(post_title);
      this->in("-------------"); this->in("");
      
      this->in("( By " + author_name + " )"); this->in("");
      this->in("<->"); this->in("");
      this->in("__END_CENTER__");

      // End
      this->in("__END__");
    }

    // How To
    void post_content(string content){
      // Start
      this->in("__START__"); this->in("");
      // Centered Content

      this->in("Post");
      this->in("----"); this->in("");
      
      this->in(content); this->in("");

      // End
      this->in("__END__");
    }
};

#endif