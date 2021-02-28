#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define max_size 100001

using namespace std;

vector<pair<int,int>> tree[100001];

bool visit[100001];

int max_dist = -1;
int final_strt_from = -1;
int strt_from = -1;

int main() {
  for(int i =0 ; i<100001; i++)
    visit[i] = false;
  int n_v;
  cin>>n_v;
  for(int i = 0; i<n_v; i++){
    int v_idx;
    cin>>v_idx;
    while(true){
      int idx;
      cin>>idx;
      if(idx == -1)
        break;
      int weight;
      cin>>weight;
      tree[v_idx].push_back({idx, weight});
    }
  }

  queue<pair<int,int>> q;
  q.push({1,0});
  visit[1] = true;

  pair<int, int> big = {-1,-1};
  while(!q.empty()){
    auto top = q.front();
    if(big.second < top.second){
      big.first = top.first;
      big.second = top.second;
    }
    for(auto& walker : tree[top.first]){
      if(!visit[walker.first]){
        q.push({walker.first, walker.second + top.second});
        visit[walker.first] = true;
      }
    }
    q.pop();
  }


  for(int i =0 ; i<100001; i++)
      visit[i] = false;
  q.push({big.first, 0});
  visit[big.first] = true;
  big = {-1,-1};
  while(!q.empty()){
    auto top = q.front();
    if(big.second < top.second){
      big.first = top.first;
      big.second = top.second;
    }
    for(auto& walker : tree[top.first]){
      if(!visit[walker.first]){
        q.push({walker.first, walker.second + top.second});
        visit[walker.first] = true;
      }
    }
    q.pop();
  }
  cout<<big.second;
  return 0;
}