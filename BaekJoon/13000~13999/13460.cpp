#include <iostream>
#include <vector>

using namespace std;

vector<string> map;
int preva = -1, rx,ry,bx,by;
//direction 0,1,2,3
//          µ¿,¼­,³²,ºÏ

bool move(int &x, int &y, int direction){
  char temp = map[x][y];
  if(direction == preva)
    return false;
  if(map[x][y] =='O')
    return true;
  if(direction == 0)
    while(true){
      if(x+1 < map.size() && map[x+1][y] != '#')
      {
        if(map[x+1][y] == 'O'){
          map[x][y] = '.';
          x=x+1;
          return true;
        }
        if(map[x+1][y] != '.')
          return false;
        map[x][y] = '.';
        x = x+1;
        map[x][y] = temp;
      }
      else
        break;
    }
  
  if(direction == 1)
    while(true){
      if(x-1 >= 0 && map[x-1][y] != '#')
      {
        if(map[x-1][y] == 'O'){
          map[x][y] = '.';
          x=x-1;
          return true;
        }
        if(map[x-1][y] != '.')
          return false;
        map[x][y] = '.';
        x = x-1;
        map[x][y] = temp;
      }
      else
        break;
    }

  if(direction == 2)
    while(true){
      if(y-1 >= 0 && map[x][y-1] != '#')
      {
        if(map[x][y-1] == 'O'){
          map[x][y] = '.';
          y = y-1;
          return true;
        }
        if(map[x][y-1] != '.')
          return false;
        map[x][y] = '.';
        y = y-1;
        map[x][y] = temp;
      }
      else
        break;
    }
  
  if(direction == 3)
    while(true){
      if(y+1 < map[0].size() && map[x][y+1] != '#')
      {
       
        if(map[x][y+1] == 'O'){
          map[x][y] = '.';
          y=y+1;
          return true;
        }
        if(map[x][y+1] != '.')
          return false;
        map[x][y] = '.';
        y = y+1;
        map[x][y] = temp;
      }
      else
        break;
    }
  
  return false;
}

int simulate(vector<int>& directions){
  int preva = -1;
  int cnt = 0;
  for(auto& direction : directions){
    if(preva == direction)
      return 987654321;
    cnt++;
    bool r_fin = move(rx,ry,direction);
    bool b_fin = move(bx,by,direction);
    if(!r_fin)
      r_fin = move(rx,ry,direction);
    preva = direction;

    if(b_fin && r_fin)
      return 98765431;
    if(r_fin)
      return cnt;
  }
  return 987654321;
}

int main() {
  int width, height;
  cin>>width>>height;
  int result = 987654322;
  for(int i =0; i<width; i++){
    string temp;
    cin>>temp;
    map.push_back(temp);
    for(int j =0; j<temp.size(); j++){
      if(temp[j] == 'R'){
        rx = i;
        ry = j;
        }
      if(temp[j] == 'B'){
        bx = i;
        by = j;
        }
    }
  }
  vector<string> origin_map = map;
  int o_rx = rx,o_ry=ry,o_bx=bx,o_by=by;

  for(int i = 0; i<4*4*4*4*4*4*4*4*4*4*4; i++){
    bool skip=false;
    preva = -1;
    vector<int> way;
    int cur = i;
    for(int j = 0; j<10; j++){
      way.push_back(cur/4%4);
      cur = cur/4;
      if(j>1)
        if(way[j] == way[j-1]){
          skip = true;
          break;
          }
    }
    if(skip)
      continue;
    result = min(result, simulate(way));
    
    map = origin_map;
    rx = o_rx;
    ry = o_ry;
    bx = o_bx;
    by = o_by;
  }
  if(result > 10)
    cout<<-1;
  else
    cout<<result;
  return 0;
}