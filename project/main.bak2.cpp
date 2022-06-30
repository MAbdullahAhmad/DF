#include "iostream"

// Pages
#include "includes/OutputManager.h"
#include "includes/Pages/WelcomePage.h"

using namespace std;

OutputManager om;
WelcomePage wp;

int main(){
  om.welcome();
  om.execute(&wp);

  return 0;
}