#ifndef MODEL_USER_H
#define MODEL_USER_H

#include "iostream"
#include "../../libs/char_array.h"
#include "../CRUD.h"
#include "../MasterModel.h"

using namespace std;

// CRUD class
class User : public TokenModel{
  private:
    // CRUD Obj
    CRUD<User>* crud;

    // Entity Props
    char nick[50];
    char name[256];
    char username[50];
    char password[32];
    char role;

  public:
    //> Constructors
    User():
      TokenModel(),
      crud(new CRUD<User>(this, "users")){}

    User(
      int i,
      char* ti,
      char* nick,
      char* name,
      char* username,
      char* password,
      char role,
      time_t ct, time_t ut
    ):  User(){
        deep_copy(this->nick, nick, 50);
        deep_copy(this->name, name, 256);
        deep_copy(this->username, username, 50);
        deep_copy(this->password, password, 32);
        this->role = role;
      }

    bool create(){
      return crud->create();
    }

    //> Setters
    void set_nick(char* nick){
      deep_copy(this->nick, nick, 50);
    }

    void set_name(char* name){
      deep_copy(this->name, name, 256);
    }

    void set_username(char* username){
      deep_copy(this->username, username, 50);
    }

    void set_password(char* password){
      deep_copy(this->password, password, 32);
    }

    void set_role(char role){
      this->role = role;
    }

    // Getters
    char* get_nick(){
      return this->nick;
    }

    char* get_name(){
      return this->name;
    }

    char* get_username(){
      return this->username;
    }

    char* get_password(){
      return this->password;
    }

    char get_role(){
      return this->role;
    }


};

#endif