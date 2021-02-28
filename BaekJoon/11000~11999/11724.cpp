#include <iostream>
#include <set>
#include <vector>
using namespace std;
vector<set<int>> sets;

int get_set(int target){
  for(int i =0; i<sets.size(); i++){
    auto& walker = sets[i];
    if(walker.find(target) != walker.end()){
      return i;
    }
  }
  return -1;
}
bool used[1001];
int main(){
  for(int i =0 ; i<1001; i++){
    used[i] = false;
  }
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  int n_node, n_v;
  cin>>n_node>>n_v;
  while(n_v--){
    int a,b;
    cin>>a>>b;
    int s_a = get_set(a);
    int s_b = get_set(b);
    used[a] = true;
    used[b] = true;
    if(s_a == -1 && s_b == -1){
      set<int> temp;
      temp.insert(a);
      temp.insert(b);
      sets.push_back(temp);
    }
    if(s_a == -1 && s_b != -1){
      sets[s_b].insert(a);
    }
    if(s_a != -1 && s_b == -1){
      sets[s_a].insert(b);
    }
    if(s_a != -1 && s_b != -1){
      if(s_a == s_b)
        continue;
      sets[s_a].merge(sets[s_b]);
      sets.erase(sets.begin()+s_b);
    }
  }
  int cnt = 0;
  for(int i = 1; i<=n_node; i++)
    if(used[i] == false)
      cnt++;
  cout<<sets.size()+cnt;
  return 0;
}