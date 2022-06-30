#ifndef MODEL_USER_H
#define MODEL_USER_H

#include "iostream"
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

    bool create(){
      return crud->create();
    }
};

#endif