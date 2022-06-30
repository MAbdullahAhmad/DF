#include "iostream"
#include "vector"

// Pages
#include "includes/Models/User.h"

using namespace std;


int main(){
  User* u = new User();
  // u->crud()->create();

  bool r = u->crud()->create();
  if(r){
    cout << "Created\n";
  } else {
    cout << "Error";
    return 0;
  }
  
  vector<User> users = u->crud()->all();
  cout << users.size() << '\n';
  for(User u : users){
    cout << u.get_id() << '\n';
  }

  return 0;
}