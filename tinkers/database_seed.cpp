// Session & ControlTower
#include "vector"
#include "includes/Temp/DatabaseSeeder.h"

using namespace SessionSpace;

// Session Object
int main(){
  // Seed Admins
  admins();
  servers();

  // Return
  return 0;
}