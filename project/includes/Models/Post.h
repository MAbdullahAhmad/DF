#ifndef MODEL_Post_H
#define MODEL_Post_H

#include "iostream"
#include "../CRUD.h"
#include "../MasterModel.h"

using namespace std;

//> Post Class
class Post : public TokenModel{
  private:
    // CRUD Obj
    CRUD<Post>* _crud;

    // Entity Props
    int author_id;
    char title[256];
    char content[20000];
    int type;

  public:
    //> Constructors
    Post():
      TokenModel(),
      _crud(new CRUD<Post>(this, "Posts")){}

    Post(
      int i,
      char* ti,
      int server_id,
      int author_id,
      char* title,
      char* content,
      int type,
      time_t ct, time_t ut
    ):
      TokenModel(i, ti, ct, ut),
      server_id(si),
      author_id(author_id),
      type(type)
    {
      deep_copy(this->title, title, 256);
      deep_copy(this->content, content, 20000);
    }

    //> Setters

    void set_server_id(int server_id){
      this->server_id = server_id;
    }
    void set_author_id(int author_id){
      deep_copy(this->author_id, author_id);
    }
    void set_content(char *content){
      deep_copy(this->content, content, 20000);
    }
    void set_type(int type){
      this->type = type;
    }

    //> Getters

    int get_server_id(){
      return this->server_id;
    }
    int get_author_id(){
      return this->author_id;
    }
    char* get_content(){
      return this->content;
    }
    int get_type(){
      return this->type;
    }
   
    CRUD<Post>* crud(){
      return this->_crud;
    }
};

#endif