#ifndef MODEL_Post_H
#define MODEL_Post_H

#include "iostream"
#include "../CRUD.h"
#include "../MasterModel.h"
#include "../Models/Channel.h"

using namespace std;

//> Post Class
class Post : public TokenModel{
  private:
    // CRUD Obj
    CRUD<Post>* _crud;

    // Entity Props
    int channel_id;
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
      int channel_id,
      int author_id,
      char* title,
      char* content,
      time_t ct, time_t ut
    ):
      TokenModel(i, ti, ct, ut),
      channel_id(channel_id),
      author_id(author_id),
      _crud(new CRUD<Post>(this, "Posts"))
    {
      deep_copy(this->title, title, 256);
      deep_copy(this->content, content, 20000);
    }

    Post(
      int channel_id,
      int author_id,
      const char* title,
      const char* content
    ):
      channel_id(channel_id),
      author_id(author_id),
      _crud(new CRUD<Post>(this, "Posts"))
    {
      this->generate_id();
      this->generate_ts();
      deep_copy(this->title, title, 256);
      deep_copy(this->content, content, 20000);
    }

    //> Setters

    bool create(){
      return _crud->create();
    }

    void set_channel_id(int channel_id){
      this->channel_id = channel_id;
    }
    void set_author_id(int author_id){
      this->author_id = author_id;
    }
    void set_content(char *content){
      deep_copy(this->content, content, 20000);
    }

    // ID Generator
    void generate_id(){
      this->id = this->crud()->get_max_id() + 1;
    }
    
    //> Getters

    int get_channel_id(){
      return this->channel_id;
    }
    int get_author_id(){
      return this->author_id;
    }
    char* get_content(){
      return this->content;
    }
   
    CRUD<Post>* crud(){
      return this->_crud;
    }

    // Relations
    Channel* channel(){
      Channel* c = new Channel();
      c->set_id(this->channel_id);
      c = c->crud()->read();
      return c;
    }
    User* author(){
      User* u = new User();
      u->set_id(this->author_id);
      u = u->crud()->read();
      return u;
    }

    // Extras

    // Display Channel
    void display(MasterPage* page){
      page->in("");
      page->in("Channel-" + str(this->id) + ":");
      page->in("");
      page->in("     ID : " + str(this->id));
      page->in("     Token-ID : " + str(this->token_id));
      page->in("     Server-Id : " + str(this->channel_id));
      page->in("     Title : " + str(this->title));
      page->in("     Timestamps : [Created: " + str(this->created_ts) + "] [Updated: " + str(this->updated_ts) + "]");
      page->in("");
      page->in("__END__");
    }

    // Row Display Channel
    void row_display(MasterPage* page){
      page->in("");
      page->in("  [ID : " + str(this->id) + ", Channel: " + this->channel()->get_title() + ", Author: " + this->author()->get_name() + ", Post Title: " + this->title + "]");
      page->in("__END__");
    }
};

#endif