#ifndef MODEL_Reaction_H
#define MODEL_Reaction_H

#include "iostream"
#include "../CRUD.h"
#include "../MasterModel.h"

using namespace std;

// Reaction Class
class Reaction: public TokenModel{
  private:
    // CRUD Obj
    CRUD<Reaction>* _crud;

    // Entity Props
    char label[20];
    char ascii[10];

  public:
    //> Constructors
    Reaction():
      TokenModel(),
      _crud(new CRUD<Reaction>(this, "Reactions")){}

    Reaction(
      int i,
      char* ti,
      char* label,
      char* ascii,
      time_t ct, time_t ut
    ):
      TokenModel(i, ti, ct, ut),
    {
        deep_copy(this->lable, label, 20);
        deep_copy(this->ascii, ascii, 10);
    }

    //> Setters
    void set_label(char* label){
      deep_copy(this->label, label, 20);
    }
    void set_ascii(char* ascii){
      deep_copy(this->ascii, ascii, 10);
    }

    //> Getters
     char* get_ascii(){
      return this->ascii;
    }
     char* get_label(){
      return this->label;
    }
   
    CRUD<Reaction>* crud(){
      return this->_crud;
    }
};

#endif