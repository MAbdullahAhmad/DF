#ifndef CHANNELS_PAGE_H
#define CHANNELS_PAGE_H

#include "iostream"
#include "../MasterPage.h"
#include "../Models/Post.h"
#include "../Session.h"

class Channels : public MasterPage{
  private:

  public:
    //> Constructors
    Channels(){
      this->run();
    }
    Channels(bool r){
      if(r) this->run();
    }

    // Run Welcome Page
    void run(){
      this->topbar();
    }

    //> Sections

    // Topbar
    void topbar(){
      // Start
      this->in("__START__"); this->in("");
      
      // Right Content
      this->in("[B] Back to Main Form");

      // End
      this->in("__END__");
    }

    // Landing
    void landing(string channel_name){
      // Start
      this->in("__START__"); this->in("");
      // Centered Content
      this->in("__CENTER__");

      this->in("Main Form");
      this->in("-------------"); this->in("");
      
      this->in(channel_name + " : Posts"); this->in("");
      this->in("You can Browse and create Posts as follow"); this->in("");
      this->in("<->"); this->in("");
      this->in("__END_CENTER__");

      // End
      this->in("__END__");
    }

    // Create Post
    void create_post(){
      this->in("__START__");
      this->in("");
      this->in("Create Post"); this->in("");
      this->in("[C] Create a New Post.");
      this->in("");
      this->in("__END__");
    }

    // Display Posts
    void display_posts(vector<Post> posts, int channel_id){
      this->in("__START__");
      this->in("");
      this->in("ALL Posts");
      this->in("---------");
      this->in("Posts are as follow:");
      this->in("__END__");
      for(Post p : posts){
        if(p.get_channel_id() == channel_id){
          p.row_display(this);
        }
      }
    }

    // Select Pos
    void select_post(){
      this->in("__START__");
      this->in("");
      this->in("Select a Post");
      this->in("__RIGHT__");
      this->in("[S] Select a Channel");
      this->in("__END_RIGHT__");
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