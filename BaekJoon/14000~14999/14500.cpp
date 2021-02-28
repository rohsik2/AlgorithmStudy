#include <iostream>
#include <set>

using namespace std;

int board[512][512] = {0,};

int BFS(int x, int y, int depth,int sum, set<int> s){
  if(s.find(x*512+y) != s.end())
    return -1;
  s.insert(x*512+y);
  sum += board[x][y];
  depth++;
  if(depth == 4)
    return sum;
  else{
    return max(
      max(BFS(x+1, y, depth, sum, s),BFS(x-1, y, depth, sum, s)),
      max(BFS(x, y+1, depth, sum, s),BFS(x, y-1, depth, sum, s))
    );
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int a,b;
  cin>>a>>b;
  for(int i =0; i<a; i++){
    for(int j = 0; j<b; j++){
      cin>>board[i+5][j+5];
      }
  }
  int big = -1;
  for(int i = 0; i<a; i++){
    for(int j =0; j<b; j++){
      set<int> s;
      big = max(big, BFS(i+5,j+5,0,0,s));
    }
  }

  for(int i =5; i<a+5; i++){
    for(int j =5; j<b+5; j++){
      int sum = 0;
      sum += board[i+1][j];
      sum += board[i-1][j];
      sum += board[i][j+1];
      sum += board[i][j-1];
      sum += board[i][j];
      sum -= min(
        min(board[i-1][j],board[i+1][j]),
        min(board[i][j-1],board[i][j+1])
        );
      big = max(big, sum);
    }
  }
  cout<<big;
  return 0;
}