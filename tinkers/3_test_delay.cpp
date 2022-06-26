#include<iostream>
#include<chrono>
#include<thread>
using namespace std;

int main(){
  using namespace std::this_thread;
  using namespace std::chrono;

  sleep_for(nanoseconds(1000000000));
  cout << "CHDKI\n";
  
  sleep_for(nanoseconds(1000000000));
  cout << "FUKI\n";
  
  return 0;
}