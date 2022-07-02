// Session & ControlTower
#include "includes/Session.h"
#include "includes/ControlTower.h"

using namespace SessionSpace;

// Session Object
int main(){
  // Setup Session
  session = new Session;

  // Initialize Routes and Enter ControlTower
  init_routes();

  // Return
  return 0;
}