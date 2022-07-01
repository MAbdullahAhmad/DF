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
    int author_id;
    char title[256];
    char content[20000];

  public:
    //> Constructors
    Post():
      TokenModel(),
      _crud(new CRUD<Post>(this, "Posts")){}

    Post(
      int i,
      char* ti,
      int ai,
      char* title,
      char* content
    ):
      TokenModel(i, ti),
      server_id(si)
      Channel(title)
    {
      deep_copy(this->author_id, type, 30);
      deep_copy(this->content, title, 256);
    }

    //> Setters

    void set_title(char* title){
      deep_copy(this->title, title, 256);
    }

    void set_type(char* type){
      deep_copy(this->type, type, 30);
    }

    //> Getters
    char* get_title(){
      return this->title;
    }

    char* get_type(){
      return this->type;
    }
   
    CRUD<Channel>* crud(){
      return this->_crud;
    }
};

#endif