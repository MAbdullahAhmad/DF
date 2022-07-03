#include "iostream"
#include "vector"

// Pages
#include "includes/Models/Post.h"

using namespace std;

int main(){
  Post u;
  
  cout << "\n\n";
  for(Post p: u.crud()->all()){
    cout << p.get_id() << '\n';
    cout << p.get_author_id() << '\n';
    cout << p.get_channel_id() << '\n' << '\n';
  }

  return 0;
}