#ifndef SERVICE_POPUP_H
#define SERVICE_POPUP_H

#include "iostream"
#include "../../libs/string_lib.h"
#include "../MasterPage.h"
#include "../OutputManager.h"

using namespace std;

class PopupService : public MasterPage{
  private:

  public:
    //> Constructors
    PopupService(){
    }

    PopupService(string message):PopupService(){
      this->run(message);
    }
    PopupService(string message, vector<string> commands):PopupService(){
      this->run(message, commands);
    }
    PopupService(string title, string message):PopupService(){
      this->run(title, message);
    }
    PopupService(string title, string message, string command):PopupService(){
      this->run(title, message, command);
    }
    PopupService(string title, string message, vector<string> commands):PopupService(){
      this->run(title, message, commands);
    }

    // Main Run
    void run(string title, string message, vector<string> commands){
      OutputManager output_manager;

      // Start
      this->in("__START__");
      
      // Right Content
      this->in("__RIGHT__");

      // Title
      if(title.length() > 0){
        this->in("");
        this->in(title);
        this->in("__END__");
      }

      // Message
      if(message.length() > 0){
        this->in("");
        this->in(message);
        this->in("__END__");
      }

      // Commands
      this->in("");
      for(string cmd : commands){
        this->in("[" + cmd.substr(0, 1) + "] " + cmd);
      }
      this->in("__END_RIGHT__");

      // End
      this->in("__END__");

      // Command
      string _cmd;
      output_manager.execute(this); 
      _cmd = get_command();
      if(!in_ch_commands(_cmd, commands))
        run(title, message, commands);
    }

    // Run Extensions
    void run(string title, string message, string command){
      vector<string> commands;
      commands.push_back(command);
      this->run(title, message, commands);
    }
    void run(string title, string message){
      this->run(title, message, "Ok");
    }
    void run(string message){
      this->run("", message);
    }
    void run(string message, vector<string> commands){
      this->run("", message, commands);
    }
};

#endif