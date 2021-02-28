#include <iostream>
#include <vector>

using namespace std;

int result[500001];

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  for(int i =0; i<500001; i++){
    result[i]  =0;
  }
  int n_tower;
  cin>>n_tower;
  vector<pair<int,int>> v;
  for(int i =1; i<=n_tower; i++){
    int temp;
    cin>>temp;
    while(v.size() > 0 && temp >= v.back().second){
      v.pop_back();
    }
    if(v.size() > 0)
      result[i] = v.back().first;
    v.push_back({i,temp});
  }
  for(int i = 1; i<= n_tower; i++)
    cout<<result[i]<<' ';
  return 0;
}