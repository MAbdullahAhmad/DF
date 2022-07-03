#ifndef CRUD_H
#define CRUD_H

#include "iostream"
#include "fstream"
#include "vector"
#include "../libs/fs.h"
using namespace std;

// Global Config
string crud_loc_prefix   =  cwd() + "records/";
string crud_loc_postfix  =  ".dat";
string tmp_file_name     =  crud_loc_prefix + "tmp" + crud_loc_postfix;

//> Class: `Reader`
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
      cout << "Aya?\n";
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
    bool is_file(){
      ifstream file(
        this->file_name,
        ios::binary | ios::in
      );
      return (bool)file;
    }
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
      cout << "Aithey Panga?\n";
      // Vector
      vector<Entity> records;
      if(!is_file()) return records;

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

//> Class: `Updater`
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

//> Class: `Deleter`
template<class Entity>
class Deleter{
  private:
    string file_name;

  public:
    //> Constructors
    Deleter():
      file_name(""){}

    Deleter(
      string file_name
    ){
      this->file_name = file_name;
    }

    //> Setters
    void set_file_name(string file_name){
      this->file_name = file_name;
    }

    //> Getters
    string get_file_name(){
      return this->file_name;
    }

    // Delete (Base)
    bool del(int record_id, bool all){
      Entity rec;
      bool deleted = false;

      // Files
      ifstream file(
        this->file_name,
        ios::binary
      );
      ofstream tmp(
        tmp_file_name,
        ios::binary | ios::trunc
      );

      while(
        file.read(
          (char*)&rec,
          sizeof(Entity)
        )
      ){
        if((record_id == rec.get_id()) && (all || (!deleted && !all))){
          deleted = true;
          continue;
        }

        if(!
          (bool)tmp.write(
            (char*)&rec,
            sizeof(Entity)
          )
        ) return false;
      }

      file.close();
      tmp.close();
      
      // Reverse Files
      ifstream rtmp(
        tmp_file_name,
        ios::binary
      );
      ofstream rfile(
        this->file_name,
        ios::binary | ios::trunc
      );

      // Tmp to File
      while(
        rtmp.read(
          (char*)&rec,
          sizeof(Entity)
        )
      ){
        if(!
          (bool)rfile.write(
            (char*)&rec,
            sizeof(Entity)
          )
        ) return false;
      }

      // Close both
      rtmp.close();
      rfile.close();

      return deleted;
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

//> Class: `CRUD`
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

    // Get Max ID
    int get_max_id(){// Open
      int id = 0;
      for(Entity e : this->all()){
        id = e.get_id();
      }
      
      return id;
    }

    // Create
    bool create(){
      // Open
      cout << "Here\n"; // @debug
      ofstream file(
        crud_loc_prefix + this->table + crud_loc_postfix,
        ios::binary | ios::out | ios::app
      );

      cout << "There\n"; // @debug
      // Confirm File Opened
      if(!(bool)file) return false;
      cout << "Where\n"; // @debug

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
      cout << "Kida fer?\n";
      cout << "Bad di gal\n";
      cout << this->table << '\n';
      Reader<Entity> records(
        crud_loc_prefix + this->table + crud_loc_postfix
      );
      cout << "Idan fer?\n";

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
      Deleter<Entity> deleter(
        crud_loc_prefix + this->table + crud_loc_postfix
      );

      // Update & Return
      return deleter.del_all(id);
    }

    // Delete All
    bool del_all(){
      return this->del_all(this->obj->get_id());
    }
};

#endif