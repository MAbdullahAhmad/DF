int main(){
  for (int i=0; i<10; i++)
  if(i%2==0)
  for(int j=0; j<5; j++)
  cout << i + j << '\n';
  else cout << i << '\n';
  cout << "rock\n";


  for (int i=0; i<10; i++)
  {if(i%2==0)
  for(int j=0; j<5; j++)
  {cout << i + j << '\n';}}
  else {cout << i << '\n';
  cout << "rock\n";}


  for (int i=0; i<10; i++){
    if(i%2==0){
      for(int j=0; j<5; j++){
        cout << i + j << '\n';
      }
    }
    else {
      cout << i << '\n';
    }
  }
  cout << "rock\n";


  Alpha a;

  // a
  //   .row()
  //   .sink()
  //   .row()
  //   .beta();

  
}