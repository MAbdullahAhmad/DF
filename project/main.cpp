#include "iostream"
#include "vector"

// Pages
#include "includes/Models/User.h"

using namespace std;

int main(){
  // User u;

  // // Create
  // // u.crud()->create();

  // u.set_id(6);
  // // Update
  // if(u.crud()->update(0, u)){
  //   cout << "Yes\n";
  // } else {
  //   cout << "No\n";
  // }

  // // Delete
  // // if(!u.crud()->del(11)) cout "Not "; cout << "Deleted\n";
  // u.crud()->del(5);

  // cout << "Near\n"; //@debug

  // u.set_id(11);

  // cout << "Rear\n"; //@debug

  // u.crud();

  // cout << "Fear\n"; //@debug

  // if(u.crud()->update(0, u)){
  //   cout << "Yes\n";
  // } else {
  //   cout << "No\n";
  // }

  // cout << "Swear\n"; //@debug

  // // Read
  // for(User u: u.crud()->all()){
  //   cout << u.get_id() << '\n';
  // }

  User u;
  u.set_id(13);
  u.crud()->create();
  if(!u.crud()->read()) cout << "Not "; cout << "Read\n";

  cout << u.get_id() << '\n';

  // u.crud()->del();

  // cout << "BEF\n";
  vector<User> users = u.crud()->all();
  // cout << "AFT\n";
  
  // for(User u: u.crud()->all()){
  for(User u: users){
    cout << u.get_id() << '\n';
  }

  return 0;
}