#ifndef CRUD_H
#define CRUD_H

#include "iostream"
#include "fstream"
#include "vector"
#include "../libs/fs.h"
using namespace std;

// Global Config
string crud_loc_prefix = cwd() + "records/";
string crud_loc_postfix = ".dat";

template<class Entity>
class Reader{
  private:
    string file_name;
    ifstream file;
    Entity record;
    int count;

  public:
    //> Constructors
    Reader():
      record(nullptr){}

    Reader(
      string file_name
    ){
      this->file_name = file_name;
    }

    // Setters
    void set_record(Entity record){
      this->record = record;
    }
    void set_file(string file_name){
      this->file_name = file_name;
      this->file.open(
        this->file_name,
        ios::binary | ios::in
      );
    }

    // Getters
    Entity* get_record(){
      return &this->record;
    }
    string get_file_name(){
      return this->file_name;
    }
    ifstream get_file(){
      return file;
    }

    // Start, Read, Next, Get, Stop, Size
    void start(){
      this->count = 0;
      this->file.open(
        this->file_name,
        ios::binary | ios::in
      );
    }
    bool read(){
      return (bool)this->file.read(
        (char*)&this->record,
        sizeof(Entity)
      ) && (bool)(++this->count);
    }
    Entity* get(){
      return &this->record;
    }
    Entity* next(){
      return this->read() ?
        &this->record :
        nullptr;
    }
    void end(){
      this->file.close();
    }
    int size(){
      return this->count;
    }

    // Get All
    vector<Entity> all(){
      // Vector
      vector<Entity> records;

      // Start, Read, Push, End
      this->start();
      this->count=0;
      while(this->read()){
        records.push_back(this->record);
        this->count++;
      }
      this->end();
      
      return records;
    }
};

// CRUD class
template<class Entity>
class CRUD{
  private:
    Entity* obj;
    string table;
    Reader<Entity>* reader;

    // Helpers
    void reader_init(){
      this->reader = new Reader<Entity>(
        crud_loc_prefix + this->table + crud_loc_postfix
      );
    }

  public:
    //> Constructors
    CRUD():
      obj(nullptr),
      table("")
    {
      this->reader_init();
    }

    CRUD(
      Entity* obj
    ):
      obj(obj),
      table("")
    {
      this->reader_init();
    }

    CRUD(
      string tbl
    ):
      obj(nullptr),
      table(tbl)
    {
      this->reader_init();
    }

    CRUD(
      Entity* obj,
      string tbl
    ):
      obj(obj),
      table(tbl)
    {
      this->reader_init();
    }

    // Setters
    void set_obj(Entity obj){
      this->obj = obj;
    }
    void set_table(string table){
      this->table = table;
    }

    // Getters
    Entity get_obj(){
      return this->obj;
    }
    string get_table(){
      return this->table;
    }

    // Create
    bool create(){
      // Open
      ofstream file(
        crud_loc_prefix + this->table + crud_loc_postfix,
        ios::binary | ios::out | ios::app
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

    // Read All
    vector<Entity> all(){
      return this->reader->all();
    }
};

#endif