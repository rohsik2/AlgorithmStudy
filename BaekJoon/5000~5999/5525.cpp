#include <iostream>
#include <string>
#include <vector>

using namespace std;

char flag = 'I';

int main() {
  ios::sync_with_stdio(false);
  int n, m;
  vector<int> v;
  v.push_back(-1);
  cin >> n >> m;
  string target;
  cin >> target;
  for(int i = 0 ; i<target.size(); i++){
    if(target[i] == flag){
      if(flag == 'I') v.back() += 1;
      flag = (flag == 'I') ? 'O' : 'I';
    }
    else{
      if(v.back() != -1){
        if(v.back() == 0)
          v.back() -= 1;
        else
          v.push_back(-1);
      }
      if(target[i] == 'I'){
        v.back() += 1;
        flag = 'O';
      }
    }
  }
  int cnt = 0;
  for(auto& walker : v){
    if(walker-n >= 0)
      cnt+= walker-n+1;
  }
  cout<<cnt;
}