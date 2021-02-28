#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int DP[12];

int solve(int target){
  if(DP[target] == 0 && target > 3)
    return DP[target] = solve(target-1) + solve(target-2) + solve(target-3);
  else
    return DP[target];
}

int main(){
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  for(int i =0 ; i<12;i++){
    DP[i] = 0;
  }
  DP[1] = 1;
  DP[2] = 2;
  DP[3] = 4;
  int n_q;
  cin>>n_q;
  while(n_q--){
    int temp;
    cin>>temp;
    cout<<solve(temp)<<'\n';
  }
  return 0;
}