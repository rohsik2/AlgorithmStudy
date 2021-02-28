#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int p_arr[100001];
int main(){
  for(int i =0 ; i<100001; i++){
    p_arr[i] = -1;
  }
  ios::sync_with_stdio(false);
  vector<int> graph[100001];
  int n_v;
  cin>>n_v;
  for(int i =0; i<n_v-1; i++){
    int a,b;
    cin>>a>>b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  queue<int> q;
  q.push(1);
  p_arr[1] = 1;
  while(!q.empty()){
    int top = q.front();
    for(auto& walker : graph[top]){
      if(p_arr[walker] == -1){
        p_arr[walker] = top;
        q.push(walker);
      }
    }
    q.pop();
  }
  for(int i = 2; i<= n_v; i++){
    cout<<p_arr[i]<<'\n';
  }

  return 0;
}