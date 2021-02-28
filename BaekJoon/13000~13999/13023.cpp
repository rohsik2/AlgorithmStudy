#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> v[2000];

bool BFS(int cur, int depth, set<int> visited){
  if(visited.find(cur) != visited.end())
    return false;

  visited.insert(cur);
  if(depth == 4)
    return true;
  
  for(auto & f : v[cur]){
    if(BFS(f, depth+1, visited)){
      return true;
    }
  }
  return false;
}


int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int n_person, n_data;
  cin>>n_person>>n_data;
  int org_n_data = n_data;
  while(n_data--){
    int a,b;
    cin>>a>>b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  for(int i =0; i<org_n_data; i++){
    set<int> visited;
    if(BFS(i, 0,visited)){
      cout<<1;
      return 0;
      }
  }
  cout<<0;
  return 0;
}