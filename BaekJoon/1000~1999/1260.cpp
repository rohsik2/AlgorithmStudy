#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> nodes[1001];

bool visit[1001];

void BFS(int cur){
  if(visit[cur] == true)
    return;
  else
    visit[cur] = true;
  cout<<cur<<' ';
  for(auto& walker : nodes[cur]){
    BFS(walker);
  }
}

void DFS(int cur, vector<int>& result){
  if(cur == result.size())
    return;
  for(auto& walker : nodes[result[cur]]){
    if(visit[walker] != true){
      result.push_back(walker);
      visit[walker] = true;
    }
  }
  DFS(++cur, result);
}

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  int n_node, n_vertex;
  cin>>n_node>>n_vertex;
  int root;
  cin>>root;
  for(int i =0 ; i<1001; i++)
    visit[i]=false;
  while(n_vertex--){
    int p,c;
    cin>>p>>c;
    nodes[p].push_back(c);
    sort(nodes[p].begin(), nodes[p].end());
    nodes[c].push_back(p);
    sort(nodes[c].begin(), nodes[c].end());
  }
  BFS(root);
  cout<<'\n';
  for(int i =0 ; i<1001; i++)
    visit[i]=false;

  vector<int> ans;
  ans.push_back(root);
  visit[root] = true;
  DFS(0,ans);
  for(auto& walker : ans)
    cout<<walker<<' ';
  return 0;
}