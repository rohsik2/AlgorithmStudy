#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<algorithm>
using namespace  std;

long long int D(long long int strt){
  return strt*2%10000;;
}

long long int S(long long int strt){
  return (strt + 9999)%10000;
}
long long int L(long long int strt){
  strt = strt%1000*10 + strt/1000;
  return strt;
}
long long int R(long long int strt){
  strt = strt/10 + strt%10*1000;
  return strt;
}
const char datas[4] = {'D','S','L','R'};
int main(){
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  int n_test;
  cin>>n_test;
  while(n_test--){

  long long int strt, dest;
  cin>>strt>>dest;
    bool visited[10000];

  for(int i = 0; i<10000; i++){
    visited[i] = false;
  }
  queue<pair<long long int,long long int>> q;
  q.push({strt, 0});
  while(!q.empty()){
    auto& top = q.front();
    if(visited[top.first]){
      q.pop();
      continue;
    }
    visited[top.first] = true;
    if(top.first == dest){
      long long int temp = top.second;
      vector<long long int> result;
      while(temp != 0){
        result.push_back(temp%10);
        temp/=10;
      }
      reverse(result.begin(), result.end());
      for(auto& walker : result)
        cout<<datas[walker-1];
      cout<<'\n';
      break;
    }
    q.push({D(top.first),top.second*10+1});
    q.push({S(top.first),top.second*10+2});
    q.push({L(top.first),top.second*10+3});
    q.push({R(top.first),top.second*10+4});
    q.pop();
  }  


  
  }
  return 0;
}