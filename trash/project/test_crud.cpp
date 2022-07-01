#include "iostream"
#include "vector"

// Pages
#include "includes/Models/User.h"

using namespace std;

int main(){
  User u;

  // Create
  u.set_id(9);
  u.crud()->create();

  // Read
  if(!u.crud()->read())
    cout << "Not ";
  cout << "Read\n";
  cout << u.get_id() << '\n';

  // Update
  u.set_id(11);
  u.crud()->update(9, u);

  // Read
  if(!u.crud()->read())
    cout << "Not ";
  cout << "Read\n";
  cout << u.get_id() << '\n';

  // Delete
  u.crud()->del();

  // Read All
  cout << "\n\n";
  for(User u: u.crud()->all()){
    cout << u.get_id() << '\n';
  }

  return 0;
}