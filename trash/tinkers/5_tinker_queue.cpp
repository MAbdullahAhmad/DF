#include<iostream>
#include<queue>

using namespace std;

int main(){
  queue<string> que;

  que.push("hello");
  que.push("hi");
  cout << que.front() << '\n';
  que.pop();
  cout << que.front() << '\n';

  return 0;
}