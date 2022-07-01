#ifndef MASTER_MODEL_H
#define MASTER_MODEL_H

#include "iostream"
#include "ctime"
#include "../libs/char_array.h"
#include "../libs/string_lib.h"

using namespace std;

class MasterModel{
  protected:
    // Props
    int id;
    time_t created_ts;
    time_t updated_ts;

    // Helpers
    int get_current_ts(){
      return time(0);
    }
  public:
    //> Constructors
    MasterModel():
      id(0),
      created_ts(this->get_current_ts()),
      updated_ts(this->get_current_ts()){}

    MasterModel(
      int i
    ):
      id(i),
      created_ts(this->get_current_ts()),
      updated_ts(this->get_current_ts()){}

    MasterModel(
      time_t c, time_t u
    ):
      id(0),
      created_ts(c), updated_ts(u){}

    MasterModel(
      int i,
      time_t c, time_t u
    ):
      id(i),
      created_ts(c), updated_ts(u){}

    //> Setters
    void set_id(int id){
      this->id = id;
    }

    void set_created_ts(time_t created_ts){
      this->created_ts = created_ts;
    }

    void set_updated_ts(time_t updated_ts){
      this->updated_ts = updated_ts;
    }

    //> Getters
    int get_id(){
      return this->id;
    }

    time_t get_created_ts(){
      return this->created_ts;
    }

    time_t get_updated_ts(){
      return this->updated_ts;
    }
};

class TokenModel{
  protected:
    // Props
    int id;
    char token_id[32];
    time_t created_ts;
    time_t updated_ts;

    // Helpers
    int get_current_ts(){
      return time(0);
    }
    char* gen_token_id(){
      return (char*)
        get_repeat_chr('0', 32)
        .c_str();
    }
  public:
    //> Constructors
    TokenModel():
      id(0),
      created_ts(this->get_current_ts()),
      updated_ts(this->get_current_ts()){}

    TokenModel(
      int i
    ):
      id(i),
      created_ts(this->get_current_ts()),
      updated_ts(this->get_current_ts()){}

    TokenModel(
      int i,
      char* ti
    ):
      id(i),
      created_ts(this->get_current_ts()),
      updated_ts(this->get_current_ts())
    {
      for(int i=0; i<32; i++){
        this->token_id[i] = ti[i];
      }
    }

    TokenModel(
      time_t c, time_t u
    ):
      id(0),
      created_ts(c), updated_ts(u){}

    TokenModel(
      int i,
      time_t c, time_t u
    ):
      id(i),
      created_ts(c), updated_ts(u){}
      
    TokenModel(
      int i,
      char* ti,
      time_t c, time_t u
    ):
      id(i),
      created_ts(c), updated_ts(u)
    {
      deep_copy(this->token_id, ti, 32);
    }

    //> Setters
    void set_id(int id){
      this->id = id;
    }

    void set_token_id(char* token_id){
      deep_copy(this->token_id, token_id, 32);
    }

    void set_created_ts(time_t created_ts){
      this->created_ts = created_ts;
    }

    void set_updated_ts(time_t updated_ts){
      this->updated_ts = updated_ts;
    }

    //> Getters
    int get_id(){
      return this->id;
    }

    char* get_token_id(){
      return this->token_id;
    }

    time_t get_created_ts(){
      return this->created_ts;
    }

    time_t get_updated_ts(){
      return this->updated_ts;
    }
};

#endif