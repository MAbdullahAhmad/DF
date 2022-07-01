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
string tmp_file_name = crud_loc_prefix + "tmp" + crud_loc_postfix;

// Reader Class
template<class Entity>
class Reader{
  private:
    string file_name;
    ifstream file;
    Entity* record;
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
    void set_record(Entity &record){
      this->record = &record;
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
      return this->record;
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
      this->record = new Entity;
      this->file.open(
        this->file_name,
        ios::binary | ios::in
      );
    }
    bool read(){
      return (bool)this->file.read(
        (char*)this->record,
        sizeof(Entity)
      ) && (bool)(++this->count);
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
    int size(){
      return this->count;
    }

    // Read One (by ID)
    Entity* read(int id){
      this->start();
      this->count=0;
      while(this->read()){
        this->count++;
        if(this->record->get_id() == id)
          return this->record;
      }
      this->end();

      return nullptr;
    }

    // Get All
    vector<Entity> all(){
      // Vector
      vector<Entity> records;

      // Start, Read, Push, End
      this->start();
      this->count=0;
      while(this->read()){
        records.push_back(*this->record);
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
      this->file.clear();
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

    //> Start, Read, Write, Next, Get, Stop, Size
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
    bool update(Entity &record){
      this->prev();
      return this->write(record);
    }

    // Update by ID : Optional : {All, One}
    bool update(int id, Entity &_new, bool all){
      Entity* rec;
      bool update = false;

      // Update
      this->start();
      while(rec = this->next()){
        if(rec->get_id() == id){
          update = this->update(_new);
          if(!all) return update;
        }
      }

      return update;
    }

    // Update by ID : One
    bool update(int id, Entity &_new){
      return this->update(id, _new, false);
    }

    // Update by ID : All
    bool update_all(int id, Entity &_new){
      return this->update(id, _new, true);
    }

    int size(){
      return this->count;
    }
};


template<class Entity>
class Deleter{
  private:
    string   file_name;
    fstream  file,       tmp_file;
    Entity   *record,    *tmp_record;
    int      count,      tmp_count;

    //> Helpers

    // Open File
    void open(bool in){
      this->file.clear();
      this->file.open(
        this->file_name,
        ios::binary | (in ? ios::in : ios::out) 
        ios::binary | (in ? ios::in : ios::out) 
      );
    }
    void open(){
      this->open(true);
    }
    void tmp_open(bool out){
      this->tmp_file.clear();
      this->tmp_file.open(
        tmp_file_name,
        ios::binary | (out ? ios::out : ios::in)
      );
    }
    void tmp_open(){
      this->tmp_open(true);
    }

  public:
    //> Constructors
    Deleter():
      record(nullptr){}

    Deleter(
      string file_name
    ){
      this->file_name = file_name;
    }

    //> Setters
    void set_record(Entity record){
      this->record = record;
    }
    void set_file(string file_name){
      this->file_name = file_name;
    }

    //> Getters
    Entity* get_record(){
      return &this->record;
    }
    string get_file_name(){
      return this->file_name;
    }
    fstream get_file(){
      return file;
    }

    //> Start, Read, Write, Next, Get, Stop, Size
    void start(bool in){
      this->count = 0;
      this->open(in);
      this->record = new Entity();
    }
    void start(){
      this->start(true);
    }
    void tmp_start(bool out){
      this->tmp_count = 0;
      this->tmp_open(out);
      this->record = new Entity();
    }
    void tmp_start(){
      this->tmp_start(true);
    }
    bool read(){
      return (bool)this->file.read(
        (char*)this->record,
        sizeof(Entity)
      ) && (bool)(++this->count);
    }
    bool tmp_read(){
      return (bool)this->tmp_file.read(
        (char*)this->tmp_record,
        sizeof(Entity)
      ) && (bool)(++this->tmp_count);
    }
    bool write(Entity &record){
      return (bool)this->file.write(
        (char*)&record,
        sizeof(Entity)
      );
    }
    bool tmp_write(Entity &record){
      return (bool)this->tmp_file.write(
        (char*)&record,
        sizeof(Entity)
      );
    }
    Entity* get(){
      return this->record;
    }
    Entity* tmp_get(){
      return this->tmp_record;
    }
    Entity* next(){
      return this->read() ?
        this->record :
        nullptr;
    }
    Entity* tmp_next(){
      return this->tmp_read() ?
        this->tmp_record :
        nullptr;
    }
    void end(){
      this->file.close();
    }
    void tmp_end(){
      this->tmp_file.close();
    }
    int size(){
      return this->count;
    }
    int tmp_size(){
      return this->tmp_count;
    }

    // Delete (Base)
    bool del(int record_id, bool all){
      Entity* rec = new Entity;
      bool deleted = false;

      // Start File and Temp File
      this->start(); this->tmp_start();

      // File to Tmp (except deletion)
      while(rec = this->next())
        if((!all && deleted) || rec->get_id() != record_id)
          if(!this->tmp_write(*rec))
            return false;
          // else continue;
          else cout << "Written Alpha\n"; //@debug
        else if (!all) deleted = true;

      // Close both
      this->end(); this->tmp_end();

      // Start Temp and File in Reverse Mode
      this->tmp_start(false); this->start(false);
      cout << "Beta St\n"; //@debug

      // // Tmp to File
      // while(rec = this->tmp_next())
      //   if(!this->write(*rec))
      //     return false;
      //   else cout << "Written\n"; //@debug

      // Tmp to File
      while(rec = this->tmp_next()){
        cout << "Beta Next\n"; //@debug
        if(!this->write(*rec))
          return false;
        else cout << "Written\n"; //@debug
      }

      // Close both
      this->tmp_end(); this->end();

      return true;
    }

    // Delete One
    bool del(int record_id){
      return del(record_id, false);
    }

    // Delete All
    bool del_all(int record_id){
      return del(record_id, true);
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

    // Read One : By Id
    Entity* read(int id){
      Reader<Entity> records(
        crud_loc_prefix + this->table + crud_loc_postfix
      );
      return records.read(id);
    }
    // Read One : Curr
    Entity* read(){
      return this->read(this->obj->get_id());
    }

    // Read All
    vector<Entity> all(){
      Reader<Entity> records(
        crud_loc_prefix + this->table + crud_loc_postfix
      );
      return records.all();
    }

    // Update One : By Id
    bool update(int id, Entity &_new){
      // Init Updator
      Updater<Entity> updator(
        crud_loc_prefix + this->table + crud_loc_postfix
      );

      // Update & Return
      return updator.update(id, _new);
    }

    // Update One : Curr
    bool update(Entity &_new){
      return this->update(this->obj->get_id(), _new);
    }

    // Update All
    bool update_all(int id, Entity &_new){
      // Init Updator
      Updater<Entity> updator(
        crud_loc_prefix + this->table + crud_loc_postfix
      );

      // Update & Return
      return updator.update_all(id, _new);
    }

    // Delete One : By Id
    bool del(int id){
      // Init Deleter
      Deleter<Entity> deleter(
        crud_loc_prefix + this->table + crud_loc_postfix
      );

      // Update & Return
      return deleter.del(id);
    }

    // Delete One : Curr
    bool del(){
      return this->del(this->obj->get_id());
    }

    // Delete All
    bool del_all(int id){
      // Init Deleter
      Updater<Entity> deleter(
        crud_loc_prefix + this->table + crud_loc_postfix
      );

      // Update & Return
      return deleter.del_all(id);
    }
};

#endif