#include "iostream"
#include "vector"

// Pages
#include "includes/Models/User.h"

using namespace std;

int main(){
  User u;
  
  cout << "\n\n";
  for(User uu: u.crud()->all()){
    cout << uu.get_id() << '\n';
  }

  return 0;
}