#include <iostream>
using namespace std;
int board[105][105];
int board2[105][105];
int n_size;
int cnt = 1;

void BFS2(int x, int y){
  board2[x][y] = cnt;
  if(x > 0)
    if(board2[x-1][y] == -1)
      BFS2(x-1, y);
  
  if(y > 0 )
    if( board2[x][y-1] == -1){
    BFS2(x, y-1);
  }
  if(x < n_size-1 )
    if( board2[x+1][y] == -1){
    BFS2(x+1, y);
  }
  if(y < n_size-1 )
    if( board2[x][y+1] == -1){
    BFS2(x, y+1);
  }
}

void BFS(int x,int y){
  board2[x][y] = cnt;
  if(x > 0)
    if(board2[x-1][y] == -1)
      BFS2(x-1, y);
  
  if(y > 0 )
    if( board2[x][y-1] == -1){
    BFS2(x, y-1);
  }
  if(x < n_size-1 )
    if( board2[x+1][y] == -1){
    BFS2(x+1, y);
  }
  if(y < n_size-1 )
    if( board2[x][y+1] == -1){
    BFS2(x, y+1);
  }
  cnt++;
}




int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  for(int i = 0; i<105; i++)
    for(int j = 0; j<105; j++){
      board[i][j] = -1;
      board2[i][j] = -1;
    }
  
  cin>>n_size;
  for(int i = 0; i<n_size; i++){
    for(int j = 0; j<n_size; j++){
     int temp;
     cin>>temp; 
     board[i][j] = temp;
    } 
  }

  int result = -1;
  
  for(int target = 0; target<100; target++){
    cnt = 1;
    for(int i = 0; i<n_size; i++){
      for(int j = 0; j<n_size; j++){
        if(board[i][j] <= target)
          board2[i][j] = 0;
        else
          board2[i][j] = -1;
      }
    }
    for(int i = 0; i<n_size; i++){
      for(int j = 0; j<n_size; j++)
        if(board2[i][j] == -1)
          BFS(i,j);
    }
    result = max(result, cnt);
  }

  if(result == 1){
    cout<<1;
    return 0;
  }
  cout<<result-1;
  return 0;

}