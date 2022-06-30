#ifndef CRUD_H
#define CRUD_H

#include "iostream"
#include "fstream"
#include "../libs/fs.h"
using namespace std;

// Global Config
string crud_loc_prefix = cwd() + "records/";
string crud_loc_postfix = ".dat";

// CRUD class
template<class Entity>
class CRUD{
  private:
    Entity* obj;
    string record_name;

  public:
    //> Constructors
    CRUD():
      obj(nullptr),
      record_name(""){}

    CRUD(
      Entity* obj
    ):
      obj(obj),
      record_name(""){}

    CRUD(
      string rn
    ):
      obj(nullptr),
      record_name(rn){}

    CRUD(
      Entity* obj,
      string rn
    ):
      obj(obj),
      record_name(rn){}

    // Setters
    // Getters

    // Create
    bool create(){
      // Open
      fstream file(
        crud_loc_prefix + this->record_name + crud_loc_postfix,
        ios::out | ios::app
      );

      // Confirm File Opened
      if(!(bool)file) return false;

      try{
        // Write
        file.write(
          (char *)this->obj,
          sizeof(Entity)
        );

        // Close
        file.close();
      } catch(exception const& e) {
        return false;
      }

      return true;
    }
};

#endif