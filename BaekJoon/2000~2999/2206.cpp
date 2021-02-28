#include<iostream>
#include<vector>
#include<string.h>
#include<set>
#include<queue>

using namespace std;

//출발점 시작 거리 DFS
//도착점 시작 거리 DFS
//주변4개중에 최소 출발점 거리 & 최소 도착점 거리 합한값으로 ㄱ

int board[1010][1010] = {1,};
int board1[1010][1010];
int board2[1010][1010];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int board2[1010][1010];
  for(int i =0; i<1010; i++){
    for(int j =0; j<1010; j++){
      board[i][j] = 1;
      board1[i][j] = 987654321;
      board2[i][j] = 987654321;
      }
  }
  int a,b;
  cin>>a>>b;
  
  for(int i = 0; i<a+1; i++){
    string temp;
    getline(cin, temp);
    if(i ==0)
      continue;
    for(int j =0; j<b; j++){
      board[i+1][j+2] = (int)temp[j]-48;
    }
  }

  int small = 987654321;

  queue<pair<pair<int,int>,int>> q;
  q.push({{2,2},0});
  while(!q.empty()){
    auto& top = q.front();
    if(board1[top.first.first][top.first.second] != 987654321
    || board[top.first.first][top.first.second] == 1){
      q.pop();
      continue;
    }
    board1[top.first.first][top.first.second] = top.second;
    q.push({{top.first.first+1,top.first.second},top.second+1});
    q.push({{top.first.first-1,top.first.second},top.second+1});
    q.push({{top.first.first,top.first.second+1},top.second+1});
    q.push({{top.first.first,top.first.second-1},top.second+1});
    q.pop();
  }

  if(board1[a+1][b+1] != 987654321)
    small = board1[a+1][b+1];

  q.push({{a+1,b+1}, 0});
  while(!q.empty()){
    auto& top = q.front();
    if(board2[top.first.first][top.first.second] != 987654321
    || board[top.first.first][top.first.second] == 1){
      q.pop();
      continue;
    }
    board2[top.first.first][top.first.second] = top.second;
    q.push({{top.first.first+1,top.first.second},top.second+1});
    q.push({{top.first.first-1,top.first.second},top.second+1});
    q.push({{top.first.first,top.first.second+1},top.second+1});
    q.push({{top.first.first,top.first.second-1},top.second+1});
    q.pop();
  }

  for(int i = 2; i<a+2; i++){
    for(int j = 2; j<b+2; j++){
      if(board[i][j] == 1){
        int s1 = 987654321;
        int s2 = 987654321;
        
        s1 = min(s1, board1[i+1][j]);
        s1 = min(s1, board1[i-1][j]);
        s1 = min(s1, board1[i][j+1]);
        s1 = min(s1, board1[i][j-1]);
        if(s1 == 987654321)
          continue;
        s2 = min(s2, board2[i+1][j]);
        s2 = min(s2, board2[i-1][j]);
        s2 = min(s2, board2[i][j+1]);
        s2 = min(s2, board2[i][j-1]);
        if(s2 == 987654321)
          continue;          
        
        small = min(small, s1+s2+2);
      }
    }
  }
  if(small == 987654321)
    cout<<-1;
  else
    cout<<small+1;
  return 0;
}