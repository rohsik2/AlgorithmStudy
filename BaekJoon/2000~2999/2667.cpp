#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void spread_f(int x, int y);
void spread(int x, int y);

int datas[26][26];
vector<int> sizes;
int cnt;
int n_size;
int main() {
  cin>>n_size;
  string temp;
  sizes.push_back(0);
  for(int i = 0; i<n_size; i++){
    cin>>temp;
    for(int j = 0; j<n_size; j++){
      if(temp.at(j)=='1')
        datas[i][j] = -1;
      else
        datas[i][j] = 0;
    }
  }
  for(int i = 0; i<n_size; i++){
    for(int j = 0; j<n_size; j++){
      spread_f(i,j);
    }
  }
  cout<<sizes.size()-1;
  sort(sizes.begin(), sizes.end());
  for(int i = 1; i<sizes.size();i++)
    cout<<endl<<sizes[i];


}
void spread_f(int x, int y){
  if(datas[x][y] == -1){
    cnt++;
    sizes.push_back(0);
    datas[x][y] = cnt;
    sizes[cnt] =  sizes[cnt]+1;
    if(x>0)
      spread(x-1,y);
    if(y>0)
      spread(x,y-1);
    if(x<n_size-1)
      spread(x+1,y);
    if(y<n_size-1)
      spread(x,y+1);
  }
  else
    return;
}

void spread(int x, int y){
  if(datas[x][y] == -1){
    datas[x][y] = cnt;
    sizes[cnt] = sizes[cnt]+1;
    if(x>0)
      spread(x-1,y);
    if(y>0)
      spread(x,y-1);
    if(x<n_size-1)
      spread(x+1,y);
    if(y<n_size-1)
      spread(x,y+1);
  }
  else
    return;
}