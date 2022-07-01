#ifndef MODEL_Channel_H
#define MODEL_Channel_H

#include "iostream"
#include "../CRUD.h"
#include "../MasterModel.h"

using namespace std;

// CRUD class
class ServerConfig : public TokenModel{
  private:
    // CRUD Obj
    CRUD<Channel>* _crud;

    // Entity Props
    int server_id;
    char key[50];
    char value[50];
    char title[256];
    char type[30];

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
      char* type
    ):
      TokenModel(i, ti),
      server_id(si)

    {
        deep_copy(this->type, type, 30);
        deep_copy(this->title, title, 256);
    }

    //> Setters

    void set_title(char* title){
      deep_copy(this->title, title, 256);
    }
    void set_type(char* type){
      deep_copy(this->type, type, 30);
    }


    // Getters

     char* get_title(){
      return this->title;
    }

     char* get_type(){
      return this->type;
    }
   
    CRUD<Channel>* crud(){
      return this->_crud;
    }
};

#endif