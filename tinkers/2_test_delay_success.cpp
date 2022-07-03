#include<iostream>
#include<chrono>
#include<thread>
using namespace std;

int main(){
  using namespace std::this_thread;
  using namespace std::chrono;

  sleep_for(nanoseconds(10));
  sleep_until(system_clock::now() + seconds(1));
  
  sleep_for(nanoseconds(10));
  sleep_until(system_clock::now() + seconds(1));
  
  return 0;
}