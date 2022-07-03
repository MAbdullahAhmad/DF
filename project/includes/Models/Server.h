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
      int server_tag,
      time_t ct, time_t ut
    ):TokenModel(i, ti, ct, ut)
    {
      this->_crud = new CRUD<Server>(this, "servers");
      this->server_tag = server_tag;
    }

    Server(
      int server_tag
    ):server_tag(server_tag)
    {
      this->generate_id();
      this->generate_ts();
    }

    bool create(){
      return _crud->create();
    }

    //> Setters

    void set_server_tag(int server_tag){
      this->server_tag = server_tag;
    }

    //> Getters
    int get_server_tag(){
      return this->server_tag;
    }

    CRUD<Server>* crud(){
      return this->_crud;
    }

    void generate_id(){
      this->id = this->crud()->get_max_id() + 1;
    }
};

#endif