#ifndef MODEL_POST_COMMENT_H
#define MODEL_POST_COMMENT_H

#include "iostream"
#include "../../libs/string_lib.h"
#include "../CRUD.h"
#include "../MasterModel.h"
#include "User.h"

using namespace std;

//> PostComment class
class PostComment : public TokenModel{
  private:
    // CRUD Obj
    CRUD<PostComment>* _crud;

    // Entity Props
    int post_id;
    int user_id;
    char comment[300];

  public:
    //> Constructors
    PostComment():
      TokenModel(),
      _crud(new CRUD<PostComment>(this, "Comments")){}
       
    PostComment(
      int i,
      char* ti,
      int post_id,
      int user_id,
      char* comment,
      time_t ct, time_t ut
    ):
      TokenModel(i, ti, ct, ut),
      post_id(post_id),
      user_id(user_id),
      _crud(new CRUD<PostComment>(this, "Comments"))
    {
        deep_copy(this->comment, comment, 300);
    }

    bool create(){
      return _crud->create();
    }

    //> Setters
    void set_post_id(int post_id){
      this->post_id = post_id;
    }
    void set_user_id(int user_id){
      this->user_id = user_id;
    }
    void set_comment(const char* comment){
      deep_copy(this->comment, comment, 300);
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
   
    CRUD<PostComment>* crud(){
      return this->_crud;
    }

    //> Relations
    User* user(){
      User* u = new User();
      u->set_id(this->user_id);
      u = u->crud()->read();
      return u;
    }

    //> Extras

    // Row Display Channel
    void display(MasterPage* page){
      page->in("");
      page->in(this->comment);
      page->in("__RIGHT__");
      page->in("( By " + str(this->user()->get_name()) + " )");
      page->in("__END_RIGHT__");
      page->in("__END__");
    }
};

#endif