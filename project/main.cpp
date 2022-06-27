#include "iostream"
#include "includes/OutputManager.h"
#include "includes/Pages/WelcomePage.h"
using namespace std;

OutputManager output_manager;
WelcomePage wp;

int main(){
  output_manager.welcome();

  output_manager.execute(&wp);

  return 0;
}