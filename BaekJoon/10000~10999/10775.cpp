#include<iostream>

using namespace std;

int gates[100001];

int get_p(int strt){
  if(strt == 0)
    return 0;
  
  if(gates[strt] != -1){
    return gates[strt] = get_p(gates[strt]);
  }
  
  gates[strt] = strt-1;
  return strt;
}

int main(){
  cout.tie(NULL);
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  for(int i =0 ; i<100001; i++){
    gates[i] = -1;
  }
  int n_gate, n_flight;
  cin>>n_gate>>n_flight;
  int cnt =0;
  while(n_flight--){
    int target;
    cin>>target;
    if(get_p(target)!= 0)
      cnt++;
    else
      break;
  }
  cout<<cnt;
  return 0;
}