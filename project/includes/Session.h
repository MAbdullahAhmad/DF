#ifndef SESSION_H
#define SESSION_H

#include "iostream"
#include "vector"
#include "../libs/pair.h"

using namespace std;

namespace SessionSpace {
  int test = 33;

  typedef Pair<string,string> StringPair;
  class Session {
    private:
      vector<StringPair> meta;

    public:
      //> Constructors
      Session(){}
      Session(string k, string v){
        this->put(k, v);
      }
      Session(vector<StringPair> meta){
        this->meta = meta;
      }

      void put(string key, string value){
        StringPair pair(key, value);
        meta.push_back(pair);
      }

      string get(string key){
        for(StringPair pair : this->meta){
          if(key == pair.key)
            return pair.value;
        }
        return "";
      }

      bool del(string key){
        int index=0;
        for(StringPair pair : this->meta){
          if(key == pair.key){
            this->meta.erase(this->meta.begin() + index);
            return true;
          }
          index++;
        }
        return false;
      }

      bool has(string key){
        for(StringPair pair : this->meta){
          if(key == pair.key)
            return true;
        }
        return false;
      }
  };

  Session* session;

  bool auth(){
    return session->get("_auth_login") != "0";
  }
}
#endif
