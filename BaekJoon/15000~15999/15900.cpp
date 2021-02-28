#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v[500001];
bool visited[500001] = {false,};
int CNT = 0;

void BFS(int idx, int depth){
  if(visited[idx])
    return;
  if(depth != 0 && v[idx].size() == 1){
    CNT += depth;
    return;
  }
  else{
    visited[idx] = true;
    int cnt = 0;
    for(auto& walker : v[idx]){
      BFS(walker, depth+1);
    }
  }
}

int main() {  
  int n_node;
  cin>>n_node;
  n_node--;
  while(n_node--){
    int a,b;
    cin>>a>>b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  BFS(1,0);
  if(CNT % 2 == 0)
    cout<<"No";
  else
    cout<<"Yes";
  return 0;

}