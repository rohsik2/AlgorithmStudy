#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
using namespace std;

int tree[100001][21];

int depth[100001];

int CNT = 0;

int get_parent(int cur, int step){
  CNT++;
  if(cur == 1)
    return 1;
  if(depth[cur] <= step)
    return 1;
  if(step == 0)
    return cur;
  if(step == 1)
    return tree[cur][0];
  int jmp;
  for(jmp = 1; int(pow(2,jmp))<=step; jmp++)
    continue;
  jmp--;
  if(int(pow(2,jmp)) == step)
    return tree[cur][jmp];
  return get_parent(tree[cur][jmp], step-int(pow(2,jmp)));
  
}

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  int n_data;
  cin>>n_data;
  for(int i =0; i<100001; i++){
    for(int j =0 ;j<21;j++)
      tree[i][j] = -1;
  }
  vector<int> g[100001];

  for(int i =0 ; i<n_data-1; i++){
    int p,c;
    cin>>p>>c;
    g[p].push_back(c);
    g[c].push_back(p); 
  }
  queue<int> q;
  q.push(1);
  bool used[100001];
  for(int i =0 ; i<100001; i++)
    used[i] = false;
  used[1] = true;
  depth[1] = 0;
  while(q.size()){
    int cur = q.front();
    for(auto& walker : g[cur]){
      int i;
      for(i =1 ; pow(2,i) < depth[walker]; i++){
        tree[cur][i] = tree[tree[cur][i-1]][i-1];
      }
      tree[cur][i] = tree[tree[cur][i-1]][i-1];
      if(!used[walker]){
        depth[walker] = depth[cur]+1;
        tree[walker][0] = cur;
        q.push(walker);
        used[walker] = true;
      }
    }
    q.pop();
  }

  int n_query;
  cin>>n_query;
  while(n_query--){
    int strt, dest;
    cin>>strt>>dest;
    if(depth[strt] > depth[dest])
      strt = get_parent(strt, depth[strt]-depth[dest]);
    else
      dest = get_parent(dest, depth[dest]-depth[strt]);
    while(true){
      if(strt == dest){
        cout<<strt<<'\n';
        break;
      }
      else {
        /*
        int jmp = 1;
        if(get_parent(strt, 1) != get_parent(dest, 1)){
          int a = get_parent(strt, jmp);
          int b = get_parent(dest, jmp);
          while(a!=b) {
            jmp*=2;
            a = get_parent(strt, jmp);
            b = get_parent(dest, jmp);
          }
          strt = get_parent(strt, jmp/2);
          dest = get_parent(dest, jmp/2);
        }
        else{
          strt = get_parent(strt, 1);
          dest = get_parent(dest, 1);
        }*/
        int i;
        for(i =1 ; tree[dest][i]!=tree[strt][i]; i++);
        i--;
        dest = tree[dest][i];
        strt = tree[strt][i];
      }
    }
  }
  return 0;
}