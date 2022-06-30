#include "iostream"
#include "includes/OutputManager.h"

// Pages
#include "includes/Pages/WelcomePage.h"
#include "includes/Pages/About.h"

using namespace std;

OutputManager output_manager;
// WelcomePage wp;
About a;

int main(){
  // output_manager.welcome();
  // output_manager.execute(&wp);
  output_manager.execute(&a);

  return 0;
}