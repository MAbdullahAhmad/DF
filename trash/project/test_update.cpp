#include "iostream"
#include "vector"

// Pages
#include "includes/Models/User.h"

using namespace std;

int main(){
  User u;

  // Create
  // u.crud()->create();

  u.set_id(5);
  // Update
  if(u.crud()->update(0, u)){
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }

  // Read
  for(User u: u.crud()->all()){
    cout << u.get_id() << '\n';
  }

  return 0;
}