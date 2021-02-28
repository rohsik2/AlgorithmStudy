#include<iostream>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n_round;
  cin>>n_round;
  int n_input;
  cin>>n_input;
  while(n_input--){
    int a,b;
    cin>>a>>b;
    if(a==b){
      cout<<1<<'\n';
      continue;
      }

    if(b>a && n_round-b+a+1 < b)
      cout<<0<<'\n';
    else if (b>a)
      cout<<1<<'\n';
    
    if(b<a && n_round-a+b+2 < a)
      cout<<0<<'\n';
    else if(b<a)
      cout<<1<<'\n';
  }
  return 0;
}