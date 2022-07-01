#ifndef MODEL_Reaction_H
#define MODEL_Reaction_H

#include "iostream"
#include "../CRUD.h"
#include "../MasterModel.h"

using namespace std;

// CRUD class
class Reaction: public TokenModel{
  private:
    // CRUD Obj
    CRUD<Reaction>* _crud;

    // Entity Props
    char lable[20];
    char ascii[10];

  public:
    //> Constructors
    Reaction():
      TokenModel(),
      _crud(new CRUD<Reaction>(this, "Reactions")){}

    Reaction(
      int i,
      char* ti,
      int si, // server_id
      char* l,
      char* ascii,
      time_t ct, time_t ut
    ):
      TokenModel(i, ti, ct, ut),
      server_id(si),
      post_id(pi),
      Reactions(l,ascii)

    {
        deep_copy(this->lable,l, 20);
        deep_copy(this->ascii, ascii, 10);
    }

    //> Setters

    void set_lable(char* lable){
      deep_copy(this->lable, l, 20);
    }
    void set_ascii(char* ascii){
      deep_copy(this->ascii, ascii, 10);
    }


    // Getters

     char* get_ascii(){
      return this->ascii;
    }

     char* get_lable(){
      return this->lable;
    }
   
    CRUD<Reaction>* crud(){
      return this->_crud;
    }
};

#endif