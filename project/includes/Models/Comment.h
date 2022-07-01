#ifndef MODEL_Comment_H
#define MODEL_Comment_H

#include "iostream"
#include "../CRUD.h"
#include "../MasterModel.h"

using namespace std;

// CRUD class
class Comment : public TokenModel{
  private:
    // CRUD Obj
    CRUD<Comment>* _crud;

    // Entity Props
    char* comment[300];

  public:
    //> Constructors
    Comment():
      TokenModel(),
      _crud(new CRUD<Comment>(this, "Comments")){}
type, type, 30);
       
    Comment(
      int i,
      char* ti,
      int pi, // post_id
      char* com,
      time_t ct, time_t ut
    ):
      TokenModel(i, ti, ct, ut),
      server_id(si),
      post_id(pi),
      comment(com)
    {
        deep_copy(this->comment, com, 300);
    }

  //> Setters
    void set_Comment(char* comment){
      deep_copy(this->comment, com, 300);
    }
    
  //> Getters
    char* get_Comment(){
      return this->comment;
    }
   
    CRUD<Comment>* crud(){
      return this->_crud;
    }
};

#endif