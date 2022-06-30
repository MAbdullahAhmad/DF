#ifndef MODEL_SERVER_H
#define MODEL_SERVER_H

#include "iostream"
#include "../CRUD.h"
#include "../MasterModel.h"

using namespace std;

// CRUD class
class Server : public TokenModel{
  private:
    // CRUD Obj
    CRUD<Server>* crud;

    // Entity Props
    int server_tag;

  public:
    //> Constructors
    Server():
      TokenModel(),
      crud(new CRUD<Server>(this, "servers")){}

    Server(
      int i,
      char* ti,
      int st,
      time_t ct, time_t ut
    ):
      Server(),
      TokenModel(i, ti, ct, ut),
      server_tag(st){}

    bool create(){
      return crud->create();
    }
};

#endif