#include "iostream"
#include "vector"

// Pages
#include "includes/OutputManager.h"
#include "includes/Models/User.h"
#include "includes/Pages/AdminUsers.h"

using namespace std;

int main(){
  OutputManager om;
  User u;
  AdminUsers au(false);
  
  cout << "\n\n";
  for(User uu: u.crud()->all()){
    uu.display(&au);
  }

  om.execute(&au);

  return 0;
}