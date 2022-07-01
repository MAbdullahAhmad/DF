#ifndef MODEL_SERVER_H
#define MODEL_SERVER_H

#include "iostream"
#include "../CRUD.h"
#include "../MasterModel.h"

using namespace std;

//> Server
class Server : public TokenModel{
  private:
    // CRUD Obj
    CRUD<Server>* _crud;

    // Entity Props
    int server_tag;

  public:
    //> Constructors
    Server():
      TokenModel(),
      _crud(new CRUD<Server>(this, "servers")){}

    Server(
      int i,
      char* ti,
      int st,
      time_t ct, time_t ut
    ):
      Server(),
      TokenModel(i, ti, ct, ut),
      server_tag(st)
      {
        deep_copyI(this->server_tag,si);
      }

    //> Setters

    void set_server_tag(char* title){
      deep_copy(this->server_tag, si);
    }

    //> Getters
     char* get_server_tag(){
      return this->server_tag;
    }

    CRUD<Server>* crud(){
      return this->_crud;
    }
};

#endif