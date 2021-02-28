#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
  int strt, dest;
  cin>>strt>>dest;
  vector<int> v[100000];
  bool visited[200001] = {false,};
  v[0].push_back(strt);
  if(strt >= dest){
    cout<<strt-dest;
    return 0;
  }
  for(int i =0; i<99999; i++){
    for(auto& walker : v[i]){
      if(walker*2 < 200000 && !visited[walker*2]){
        v[i+1].push_back(walker*2);
        visited[walker] = true;
        }
      if(walker-1 > 0 && !visited[walker-1]){
        v[i+1].push_back(walker-1);
        visited[walker] = true;
      }
      if(walker+1 < 200000 && !visited[walker+1]){
        v[i+1].push_back(walker+1);
        visited[walker] = true;
      }
    }
    if(visited[dest]){
      
      cout<<i;
      return 0;  
    }
  }
  return 0;
}