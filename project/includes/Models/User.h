#ifndef MODEL_USER_H
#define MODEL_USER_H

#include "iostream"
#include "cstring"
#include "../../libs/char_array.h"
#include "../CRUD.h"
#include "../Session.h"
#include "../MasterModel.h"
#include "../MasterPage.h"

using namespace std;
using namespace SessionSpace;

// User class
class User : public TokenModel{
  private:
    // CRUD Obj
    CRUD<User>* _crud;

    // Entity Props
    char nick[50];
    char name[256];
    char username[50];
    char password[32];
    char role;

  public:
    //> Constructors
    User():
      TokenModel(),
      _crud(new CRUD<User>(this, "users")){}

    User(
      int i,
      const char* ti,
      const char* nick,
      const char* name,
      const char* username,
      const char* password,
      char role,
      time_t ct, time_t ut
    ):  User(){
      deep_copy(this->nick, nick, 50);
      deep_copy(this->name, name, 256);
      deep_copy(this->username, username, 50);
      deep_copy(this->password, password, 32);
      this->role = role;
    }
    User(
      const char* nick,
      const char* name,
      const char* username,
      const char* password,
      char role
    ): User() {
      // Generate ID and TS
      this->generate_id();
      this->generate_ts();

      // Set Props
      deep_copy(this->nick, nick, 50);
      deep_copy(this->name, name, 256);
      deep_copy(this->username, username, 50);
      deep_copy(this->password, password, 32);

      this->role = role;
    }

    bool create(){
      return _crud->create();
    }

    //> Setters
    void set_nick(char* nick){
      deep_copy(this->nick, nick, 50);
    }

    void set_name(char* name){
      deep_copy(this->name, name, 256);
    }

    void set_username(char* username){
      deep_copy(this->username, username, 50);
    }

    void set_password(char* password){
      deep_copy(this->password, password, 32);
    }

    void set_role(char role){
      this->role = role;
    }

    void generate_id(){
      this->id = this->crud()->get_max_id() + 1;
    }

    // Getters
    char* get_nick(){
      return this->nick;
    }

    char* get_name(){
      return this->name;
    }

    char* get_username(){
      return this->username;
    }

    char* get_password(){
      return this->password;
    }

    char get_role(){
      return this->role;
    }

    CRUD<User>* crud(){
      return this->_crud;
    }

    //> Extras

    // Verify User
    int verify(
      string &username,
      string &password,
      bool put
    ){
      if(
        (strcmp(username.c_str(), this->username) == 0) &&
        (strcmp(password.c_str(), this->password) == 0)
      ) {
        if(put){
          session->put("_auth_user", this->username);
          session->put("_auth_name", this->name);
          session->put("_auth_nick", this->nick);
          session->put("_auth_role", this->role == 'a' ? "a" : "u");
        }
        return this->role == 'a' ? 2 : 1;
      }
      return 0;
    }
    int verify(
      string &username,
      string &password
    ){
      return this->verify(username, password, true);
    }

    // Display User
    void display(MasterPage* page){
      page->in("");
      page->in("User-" + str(this->id) + ":");
      page->in("");
      page->in("     ID : " + str(this->id));
      page->in("     Token-ID : " + str(this->token_id));
      page->in("     Nick : " + str(this->nick));
      page->in("     Name : " + str(this->name));
      page->in("     Username : " + str(this->username));
      page->in("     Password : " + str(this->password));
      page->in("     Role : " + str(this->role == 'u' ? "User" : "Admin"));
      page->in("     Timestamps : [Created: " + str(this->created_ts) + "] [Updated: " + str(this->updated_ts) + "]");
      page->in("");
      page->in("__END__");
    }
};

#endif