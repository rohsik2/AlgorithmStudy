#include <iostream>
#include <vector>

using namespace std;
int MAX = -1987654321;
int MIN = 1987654321;

void back_track(vector<int> v, int pl, int mi, int mul, int div, int current, int idx){
  if(v.size() == idx){
    MAX = max(MAX, current);
    MIN = min(MIN, current);
    return;
  }
  int tmp = v[idx];
  if(pl>0){
    back_track(v,pl-1,mi,mul,div,current+tmp,idx+1);
  }
  if(mi>0){
    back_track(v,pl,mi-1,mul,div,current-tmp,idx+1);
  }
  if(mul>0){
    back_track(v,pl,mi,mul-1,div,current*tmp, idx+1);
  }
  if(div>0){
    back_track(v,pl,mi,mul,div-1,current/tmp, idx+1);
  }
}

int main() {
  int n_num;
  vector<int> numbers;
  vector<int> temp;
  cin>>n_num;
  for(int i =0; i<n_num ; i++){
    int tmp;
    cin>>tmp;
    temp.push_back(tmp);
  }

  int pl,mi,mul,div;
  cin>>pl>>mi>>mul>>div;
  int current = temp[0];
  back_track(temp, pl, mi, mul, div, current, 1);
  cout<<MAX<<'\n'<<MIN;
  return 0;
}