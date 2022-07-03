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
    int channel_id;
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
      int channel_id,
      int author_id,
      char* title,
      char* content,
      int type,
      time_t ct, time_t ut
    ):
      TokenModel(i, ti, ct, ut),
      channel_id(channel_id),
      author_id(author_id),
      type(type)
    {
      deep_copy(this->title, title, 256);
      deep_copy(this->content, content, 20000);
    }

    //> Setters

    void set_channel_id(int channel_id){
      this->channel_id = channel_id;
    }
    void set_author_id(int author_id){
      this->author_id = author_id;
    }
    void set_content(char *content){
      deep_copy(this->content, content, 20000);
    }
    void set_type(int type){
      this->type = type;
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
    int get_type(){
      return this->type;
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
      page->in("  [ID : " + str(this->id) + ", Channel: " + str(this->channel_id) + " (" + this->channel()->get_title() + "), Post Title: " + this->title + "]");
      page->in("__END__");
    }
};

#endif