#include<iostream>

using namespace std;

#include <iostream>
using namespace std;

void draw(bool board[51][51], int x, int y, int width, int height){
  if(board[x][y]){
    board[x][y] = false;
  }
  else
    return;
  if(x>=1)
    draw(board, x-1,y,width,height);
  if(y>=1)
    draw(board, x,y-1,width,height);
  if(x<=width)
    draw(board, x+1,y,width,height);
  if(y<=height)
    draw(board, x,y+1,width,height);
}

int calc(bool board[51][51],int width, int height){
  int cnt = 0;
  for(int i = 0; i<width; i++){
    for(int j = 0; j<height; j++){
      if(board[i][j]){
        draw(board, i, j,width,height);
        cnt++;
      }
    }
  }
  return cnt;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
  int testcase;
  cin >> testcase;
  while(testcase--){
    int width, height, num;
    cin >> width >> height >> num;
    bool board[51][51];
    for(int i =0; i<=50; i++){
      for(int j = 0; j<=50; j++){
        board[i][j] = false;
      }
    }
    for(int i = 0 ; i<num; i++){
      int x,y;
      cin>>x>>y;
      board[x][y] = true;
    }
    int result = calc(board,width,height);
    cout<<result<<endl;
  }
}


