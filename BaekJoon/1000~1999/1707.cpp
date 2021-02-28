#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> v[20001];

bool BFS(int cur, bool* visited, set<int>& s1, set<int>& s2){
  if(visited[cur])
    return true;
  visited[cur] = true;
  bool result = true;
  for(int f : v[cur]){
    if(s1.find(f) != s1.end())
      return false;
    s2.insert(f);
    result = BFS(f, visited, s2, s1) && result;
    if(!result)
      return false;
  }
  return result;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n_case;
  cin>>n_case;
  for(int i =0; i<n_case; i++){
    int n_v, n_e;
    cin>>n_v>>n_e;
    for(int j = 0; j<20001; j++)
      v[j].clear();
    for(int j =0; j<n_e; j++){
      int a,b;
      cin>>a>>b;
      v[a].push_back(b);
      v[b].push_back(a);
    }
    bool visited[20000] = {false,};
    set<int> s1, s2;
    bool result = false;
    for(int j = 0; j<n_v+1; j++){
      if(!BFS(j, visited, s1, s2)){
        cout<<"NO";
        result = true;
        break;
        }
    }
    if(!result)
      cout<<"YES";
    cout<<'\n';
  }

}