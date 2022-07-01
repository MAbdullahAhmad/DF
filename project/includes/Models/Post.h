#ifndef MODEL_Post_H
#define MODEL_Post_H

#include "iostream"
#include "../CRUD.h"
#include "../MasterModel.h"

using namespace std;

// CRUD class
class Post : public TokenModel{
  private:
    // CRUD Obj
    CRUD<Post>* _crud;

    // Entity Props
    int ai;
    int pi;
    char title[256];
    char content[20000];

  public:
    //> Constructors
    Post():
      TokenModel(),
      _crud(new CRUD<Post>(this, "Posts")){}

    Post(
      int i,
      int pi,
      char* ti,
      int ai,
      char* title,
      char* content,
      time_t ct, time_t ut
    ):
      TokenModel(i, ti, ct, ut),
      server_id(si),
      Channel(title,type),
      post(content,pi,ai)
    {
      deep_copy(this->content, content, 20000);
      deep_copy(this-> pi,pi);
      deep_copy(this-> ai,ai);
    }

    //> Setters

    void set_type(char* ){content
      deep_copy(this->content, content, 20000);
    }

    void set_PostId(int pi){
      deep_copy(this->pi, pi);
    }

    void set_AuthorId(int ai){
      deep_copy(this->ai, ai);
    }

    //> Getters
    

    char* get_Content(){
      return this->content;
    }

    int get_PostId(){
      return this->pi;
    }

    int get_AuthorId(){
      return this->ai;
    }
   
    CRUD<Post>* crud(){
      return this->_crud;
    }
};

#endif