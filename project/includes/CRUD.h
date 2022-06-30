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

// Reader Class
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

template<class Entity>
class Updater{
  private:
    string file_name;
    fstream file;
    Entity* record;
    int count;

    //> Helpers

    // Open File
    void open(){
      this->file.open(
        this->file_name,
        ios::binary |ios::in | ios::out
      );
    }

  public:
    //> Constructors
    Updater():
      record(nullptr){}

    Updater(
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
    fstream get_file(){
      return file;
    }

    //> Movements: {to, on, total, move, prev}

    // Goto Position
    void to(int n){
      this->file.seekg(sizeof(Entity) * n);
    }

    // Get Position
    int on(){
      return this->file.tellg() / sizeof(Entity);
    }

    // Get Total Size
    int total(){
      int size, curr = this->file.tellg();
      this->file.seekg(0, ios::end);

      size = this->file.tellg();
      this->file.seekg(curr);

      return size / sizeof(Entity);
    }

    // Move n steps (+/-)
    bool move(int n){
      int loc = this->file.tellg() + sizeof(Entity) * n;

      if(loc / sizeof(Entity) <= this->total()){
        this->file.seekg(loc);
        return true;
      }
      return false;
    }

    // Goto Previous Record
    void prev(){
      this->move(-1);
    }

    // Start, Read, Write, Next, Get, Stop, Size
    void start(){
      this->count = 0;
      this->open();
      this->record = new Entity();
    }
    bool read(){
      return (bool)this->file.read(
        (char*)this->record,
        sizeof(Entity)
      ) && (bool)(++this->count);
    }
    bool write(Entity record){
      return (bool)this->file.write(
        (char*)&record,
        sizeof(Entity)
      );
    }
    Entity* get(){
      return this->record;
    }
    Entity* next(){
      return this->read() ?
        this->record :
        nullptr;
    }
    void end(){
      this->file.close();
    }

    // Update
    bool update(Entity record){
      this->prev();
      return this->write(record);
    }

    int size(){
      return this->count;
    }
};


// CRUD class
template<class Entity>
class CRUD{
  private:
    Entity* obj;
    string table;

  public:
    //> Constructors
    CRUD():
      obj(nullptr),
      table(""){}

    CRUD(
      Entity* obj
    ):
      obj(obj),
      table(""){}

    CRUD(
      string tbl
    ):
      obj(nullptr),
      table(tbl){}

    CRUD(
      Entity* obj,
      string tbl
    ):
      obj(obj),
      table(tbl){}

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
      Reader<Entity> records(
        crud_loc_prefix + this->table + crud_loc_postfix
      );
      return records.all();
    }

    bool update(int id, Entity _new){
      // Init Updator
      Updater<Entity> updator(
        crud_loc_prefix + this->table + crud_loc_postfix
      );
      Entity* record;

      // Update
      updator.start();
      while(record = updator.next()){
        if(record->get_id() == id){
          cout << record->get_id() << '\n'; // @debug
          return updator.update(_new);
        }
      }

      // In case nothing updated
      return false;
    }

    bool update_all(int id, Entity _new){
      // Init Updator
      Updater<Entity> updator(
        crud_loc_prefix + this->table + crud_loc_postfix
      );
      Entity* record;
      bool update = false;

      // Update
      updator.start();
      while(record = updator.next()){
        if(record.get_id() == id){
          updator.update(_new);
          update = true;
        }
      }
      updator.close();

      // Return Result
      return update;
    }
};

#endif