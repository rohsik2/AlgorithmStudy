#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int dp[61][61][61];

int solve(int x, int y, int z){
  if(x < 0) x = 0;
  if(y < 0) y = 0;
  if(z < 0) z = 0;
  if(dp[x][y][z] != 987654321)
    return dp[x][y][z];
  int small = 987654321;

  vector<int> v;
  v.push_back(1);
  v.push_back(3);
  v.push_back(9);
  
  do{
    small = min(solve(x-v[0],y-v[1],z-v[2])+1, small);
  }while(next_permutation(v.begin(), v.end()));
  
  return dp[x][y][z] = small;
}

int main() {
  int n_scv;
  cin>>n_scv;

  vector<int> target;
  while(n_scv --){
    int temp;
    cin>>temp;
    target.push_back(temp);
  }

  while(target.size() < 3){
    target.push_back(0);
  }

  for(int x = 0; x<61; x++){
    for(int y = 0; y<61; y++){
      for(int z= 0; z<61; z++){
        dp[x][y][z] = 987654321;
      }
    }
  }
  
  
  dp[0][0][0] = 0;
  cout<<solve(target[0],target[1],target[2]);
  return 0;
}