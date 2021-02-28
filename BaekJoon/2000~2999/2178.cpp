#include <iostream>
#include <vector>

using namespace std;
int w,h;
char board[101][101];
vector<pair<int,int>> todo;
int cnt = 1;
void solve(){
  vector<pair<int,int>> n_vec;
  for(auto& walker : todo){
    int a = walker.first;
    int b = walker.second;
    if(a == h-1 && b == w-1)
      return;
    if(board[a][b] == '1'){
      board[a][b] = '0';
      if(a > 0)
        n_vec.push_back({a-1,b});
      if(a < h-1)
        n_vec.push_back({a+1, b});
      if(b > 0)
        n_vec.push_back({a,b-1});
      if(b < w-1)
        n_vec.push_back({a, b+1});
    }
    else
      continue;
  }
  cnt++;
  /*
  for(auto& walker : todo){
    cout<<" "<<walker.first<<","<<walker.second<<endl;
  }
  if(cnt > 20)
    return;*/
  todo = n_vec;
  solve();
}

int main() {
  cin>>h>>w;
  todo.push_back({0,0});
  for(int i = 0; i<h; i++){
    cin>>board[i];
  }
  solve();
  cout<<cnt;
}