// Session & ControlTower
#include "vector"
#include "includes/Temp/DatabaseSeeder.h"

using namespace SessionSpace;

// Session Object
int main(){
  // Seed Admin
  AdminSeeder::run();

  // Return
  return 0;
}