#ifndef DATABASE_SEEDER_H
#define DATABASE_SEEDER_H

#include "iostream"
#include "vector"
#include "../Models/User.h"
#include "../Models/Server.h"
#include "../Models/Post.h"

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

void servers(){
  vector<Server> servers;
  // char tag[32] = "";
  string tag = "1234";
  char tmp[32];
  strcpy(tmp, tag.c_str());
  Server s(
    1,
    tmp,
    1,
    1656803922, 1656803922
  );

  servers.push_back(s);

  for(Server s : servers)
    s.create();
}

void posts(){
  vector<Post> posts;
  // char tag[32] = "";
  string tag = "1234";
  char tmp[32];
  strcpy(tmp, tag.c_str());
  Server s(
    1,
    tmp,
    1,
    1656803922, 1656803922
  );

  servers.push_back(s);

  for(Server s : servers)
    s.create();
}

#endif
