#include <iostream>
#include <vector>
using namespace std;

vector<int> nodes[26];

void pre(int cur){
  cout<<char(cur + 'A');
  for(auto& walker :nodes[cur]){
    if(walker != -1)
      pre(walker);
  }
}
void ino(int cur){
  if(cur == -1)
    return;
  if(nodes[cur].size() > 0)
    ino(nodes[cur][0]);
  cout<<char(cur + 'A');
  if(nodes[cur].size() > 1)
    ino(nodes[cur][1]);
}
void post(int cur){
  for(auto& walker :nodes[cur]){
    if(walker != -1)
      post(walker);
  }
  cout<<char(cur + 'A');
}

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  int n_node;
  cin>>n_node;
  while(n_node--){
    char a,b,c;
    cin>>a>>b>>c;
    if(b != '.')
      nodes[int(a-'A')].push_back(int(b - 'A'));
    else
      nodes[int(a-'A')].push_back(-1);
    if(c != '.')
      nodes[int(a-'A')].push_back(int(c - 'A'));
    else
      nodes[int(a-'A')].push_back(-1);
  }
  pre(0);
  cout<<'\n';
  ino(0);
  cout<<'\n';
  post(0);
  cout<<'\n';
  return 0;
}