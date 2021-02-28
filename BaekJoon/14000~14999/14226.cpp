#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dp[2001][2001] = {987654321,};

queue<pair<pair<int,int>,int>> q;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n_target;
  cin>>n_target;
  q.push({{1,0},0});
  for(int i =0; i<2001*2001; i++){
    dp[i/2001][i%2001] = 987654321;
  }
  while(!q.empty()){
    auto walker = q.front();
    if(walker.first.first == n_target){
      cout<<walker.second;
      return 0;
    }
    if(walker.first.first > n_target*2){
      q.pop();
      continue;
    }
    if(dp[walker.first.first][walker.first.second] == 987654321){
      dp[walker.first.first][walker.first.second] = walker.second;
      q.push({{walker.first.first, walker.first.first}, walker.second+1});
      q.push({{walker.first.first+walker.first.second, walker.first.second}, walker.second+1});
      if(walker.first.first >= 2)
        q.push({{walker.first.first-1, walker.first.second}, walker.second+1});
    }
    q.pop();
  }
  return 0;
}