#include<iostream>
#include<vector>

using namespace std;

int main(){
  vector<string> vec;

  vec.push_back("Hello");
  cout << vec.size() << '\n';
  vec.push_back("Hi");
  cout << vec.size() << '\n';
  cout << vec[vec.size()-1] << '\n';
  vec.pop_back();
  cout << vec.size() << '\n';

  return 0;
}