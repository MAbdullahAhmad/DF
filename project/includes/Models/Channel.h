#ifndef MODEL_Channel_H
#define MODEL_Channel_H

#include "iostream"
#include "../CRUD.h"
#include "../MasterModel.h"

using namespace std;

//> Channel Class
class Channel : public TokenModel{
  private:
    // CRUD Obj
    CRUD<Channel>* _crud;

    // Entity Props
    int server_id;
    char title[256];
    int type;

  public:
    //> Constructors
    Channel():
      TokenModel(),
      _crud(new CRUD<Channel>(this, "Channels")){}

    Channel(
      int i,
      char* ti,
      int si, // server_id
      char* title,
      int type
    ):
      TokenModel(i, ti),
      server_id(si),
      type(type)
    {
      this->_crud = new CRUD<Channel>(this, "Channels");
      deep_copy(this->title, title, 256);
    }

    Channel(
      int si, // server_id
      const char* title,
      int type
    ):
      server_id(si),
      type(type)
    {
      cout << "Kidan?\n";
      this->_crud = new CRUD<Channel>(this, "Channels");
      // Generate ID and TS
      this->generate_id();
      this->generate_ts();
      cout << "Aidan?\n";
      
      deep_copy(this->title, title, 256);
    }

    //> Setters
    void set_title(char* title){
      deep_copy(this->title, title, 256);
    }
    void set_type(int type){
      this->type = type;
    }

    void generate_id(){
      cout << "Pelan\n";
      this->id = 0;
      try{
        this->id = this->crud()->get_max_id() + 1;
      } catch(exception const& e) {
        this->id = 1;
      }
      cout << "Bachon\n";
    }

    // Getters
    char* get_title(){
      return this->title;
    }

    int get_type(){
      return this->type;
    }
   
    CRUD<Channel>* crud(){
      return this->_crud;
    }
    
    bool create(){
      cout << "Smare\n"; // @debug
      return _crud->create();
    }

    // Extras

    // Display Channel
    void display(MasterPage* page){
      page->in("");
      page->in("User-" + str(this->id) + ":");
      page->in("");
      page->in("     ID : " + str(this->id));
      page->in("     Token-ID : " + str(this->token_id));
      page->in("     Server-Id : " + str(this->server_id));
      page->in("     Title : " + str(this->title));
      page->in("");
      page->in("__END__");
    }
};

#endif