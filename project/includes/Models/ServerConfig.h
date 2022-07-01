#ifndef MODEL_ServerConfig_H
#define MODEL_ServerConfig_H

#include "iostream"
#include "../CRUD.h"
#include "../MasterModel.h"

using namespace std;

// CRUD class
class ServerConfig : public TokenModel{
  private:
    // CRUD Obj
    CRUD<ServerConfig>* _crud;

    // Entity Props
    int server_id;
    char key[50];
    char value[50];

  public:
    //> Constructors
    ServerConfig():
      TokenModel(),
      _crud(new CRUD<ServerConfig>(this, "ServerConfigs")){}

    ServerConfig(
      int i,
      char* ti,
      int si, // server_id
      char* key,
      char* value
      time_t ct, time_t ut
    ):
      TokenModel(i, ti, ct, ut),
      server_id(si),
      servers(key,value)
    {
        deep_copy(this->key, key, 50);
        deep_copy(this->value,value, 50);
    }

  //> Setters
  void set_key(char* key){
    deep_copy(this->key, key, 50);
  }
  void set_value(char* value){
    deep_copy(this->value, value, 50);
  }

  // Getters
  char* get_key(){
    return this->key;
  }
   char* get_value(){
    return this->value;
  }
  
  CRUD<ServerConfig>* crud(){
    return this->_crud;
  }
};

#endif