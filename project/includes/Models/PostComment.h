#ifndef MODEL_Comment_H
#define MODEL_Comment_H

#include "iostream"
#include "../CRUD.h"
#include "../MasterModel.h"

using namespace std;

//> PostComment class
class PostComment : public TokenModel{
  private:
    // CRUD Obj
    CRUD<Comment>* _crud;

    // Entity Props
    int post_id;
    int user_id;
    char* comment[300];

  public:
    //> Constructors
    Comment():
      TokenModel(),
      _crud(new CRUD<Comment>(this, "Comments")){}
       
    Comment(
      int i,
      char* ti,
      int post_id,
      int user_id,
      char* comment,
      time_t ct, time_t ut
    ):
      TokenModel(i, ti, ct, ut),
      post_id(post_id),
      user_id(user_id)
    {
        deep_copy(this->comment, com, 300);
    }

    //> Setters
    void set_post_id(int post_id){
      this->post_id = post_id;
    }
    void set_user_id(int user_id){
      this->user_id = user_id;
    }
    void set_comment(char* comment){
      deep_copy(this->comment, com, 300);
    }
    
    //> Getters
    int get_post_id(){
      return this->post_id;
    }
    int get_user_id(){
      return this->post_id;
    }
    char* get_comment(){
      return this->comment;
    }
   
    CRUD<Comment>* crud(){
      return this->_crud;
    }
};

#endif