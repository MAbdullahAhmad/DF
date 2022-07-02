#ifndef DATABASE_SEEDER_H
#define DATABASE_SEEDER_H

#include "iostream"
#include "vector"
#include "../Models/User.h"

using namespace std;

void admins(){
  vector<User> admin_users;
  User u(
    "admin",
    "Admin",
    "admin",
    "admin",
    'a'
  ); u.generate_id(); u.generate_ts();
  admin_users.push_back(u);

  for(User a : admin_users)
    a.create();
}

#endif
