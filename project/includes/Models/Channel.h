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
    // char key[50];
    // char value[50];
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
        deep_copy(this->title, title, 256);
    }

    //> Setters
    void set_title(char* title){
      deep_copy(this->title, title, 256);
    }
    void set_type(int type){
      this->type = type;
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
};

#endif