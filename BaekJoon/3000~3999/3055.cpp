#include <iostream>
#include <vector>
#include <queue>

using namespace std;
char board[52][52];
int row, col;

struct Data{
  char type;
  int time = 0;
  int x;
  int y;
};
queue<Data> q;

bool fin = false;

void q_push(char type, int time, int x, int y){
  if(board[y][x] == 'D'){
    cout<<time;
    fin = true;
  }
  Data temp;
  temp.type = type;
  temp.time = time;
  temp.x = x;
  temp.y = y;
  q.push(temp);
  board[y][x] = temp.type;
}

bool is_valid_w(int x, int y){
  return (board[y][x] == '.' || board[y][x] == 'S');
}
bool is_valid_s(int x, int y){
  return (board[y][x] == '.' || board[y][x] == 'D');
}

int main() {
  cin>>row>>col;

  for(int i =0; i<52*52; i++)
    board[i/52][i%52] = ' ';

  for(int i =0; i<row; i++)
  for(int j =0; j<col; j++){
    cin>>board[i+1][j+1];
    if(board[i+1][j+1] == '*'){
      Data temp;
      temp.type = '*';
      temp.x = j+1;
      temp.y = i+1;
      q.push(temp);
    }
  }
  for(int i =1; i<=row; i++) for(int j =1; j<= col; j++){
    if(board[i][j] == 'S'){
      Data temp;
      temp.type = 'S';
      temp.x = j;
      temp.y = i;
      q.push(temp);
    }
  }
  while(!q.empty()){
    auto& top = q.front();
    q.pop();
    //cout<<top.type<<top.time<<top.x<<top.y<<endl;


    if(top.type == 'S'){
      if(is_valid_s(top.x+1, top.y))
        q_push(top.type, top.time+1, top.x+1, top.y);
      if(is_valid_s(top.x, top.y+1))
        q_push(top.type, top.time+1, top.x, top.y+1);
      if(is_valid_s(top.x-1, top.y))
        q_push(top.type, top.time+1, top.x-1, top.y);
      if(is_valid_s(top.x, top.y-1))
        q_push(top.type, top.time+1, top.x, top.y-1);
    }

    if(top.type == '*'){
      if(is_valid_w(top.x+1, top.y))
        q_push(top.type, top.time+1, top.x+1, top.y);
      if(is_valid_w(top.x, top.y+1))
        q_push(top.type, top.time+1, top.x, top.y+1);
      if(is_valid_w(top.x-1, top.y))
        q_push(top.type, top.time+1, top.x-1, top.y);
      if(is_valid_w(top.x, top.y-1))
        q_push(top.type, top.time+1, top.x, top.y-1);
    }
    if(fin)
      return 0;
  }


  cout<<"KAKTUS";
}
