#include "iostream"
#include "vector"

// Pages
#include "includes/Models/User.h"

using namespace std;


int main(){
  User* u = new User();
  // u->crud()->create();

  if(u->crud()->create()){
    cout << "Created\n";
  } else {
    cout << "Error";
    return 0;
  }
  
  for(User u : u->crud()->all()){
    cout << u.get_id() << '\n';
  }

  return 0;
}