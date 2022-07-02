#ifndef DATABASE_SEEDER_H
#define DATABASE_SEEDER_H

#include "iostream"
#include "../Models/User.h"

using namespace std;

class AdminSeeder{
  private:
    static vector<User*> admins;
  
  public:
    static void run(){
      AdminSeeder::load();
      for(User* a : AdminSeeder::admins)
        a->create();
    }

    static void load(){
      admins.push_back(new User(
        "admin",
        "Admin",
        "admin",
        "admin",
        'a'
      ));
    }
};

// Static Init
vector<User*> AdminSeeder::admins;

#endif
