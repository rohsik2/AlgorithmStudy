#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


void bfs(set<int>& s, vector<int> v[], int current, bool used[]){
  int size = s.size();
  s.insert(current);
  if(size == s.size() || used[current] == true)
    return;
  for(auto& walker : v[current]){
    bfs(s,v,walker,used);
  } 
}



int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  cout.tie(NULL);

  bool used[10001];
  for(int i = 0; i<10001; i++)
    used[i] = false;

  int n_node, n_rule;
  cin>>n_node>>n_rule;
  vector<int> v1[10001];
  vector<int> v2[10001];
  for(int i =0; i<n_rule; i++){
    int a,b;
    cin>>a>>b;
    v1[a].push_back(b);
    v2[b].push_back(a);
  }

  set<int> s;
  set<int> s2;
  vector<set<int>> intersects;

  for(int i = 1 ; i<= n_node; i++){
    set<int> intersect;
    s.clear();
    s2.clear();
    intersect.clear();
    if(used[i] == false){
      bfs(s,v1,i, used);
      bfs(s2,v2,i, used);
      set_intersection(s.begin(),s.end(),s2.begin(),s2.end(),inserter(intersect,intersect.begin()));
      intersects.push_back(intersect);
      for(auto& walker : intersect)
        used[walker] = true;
    }
  }
  cout<<intersects.size()<<'\n';
  for(auto& intersect : intersects){
    for(auto& walker : intersect){
      cout<<walker <<" ";
    }
    cout<<"-1\n"; 
  }
  return 0;
}