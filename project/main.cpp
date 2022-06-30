#include "iostream"

// Pages
#include "includes/Models/User.h"

using namespace std;


int main(){
  User u;
  if(!u.create()) cout << "Not ";
  cout << "Created\n";

  return 0;
}