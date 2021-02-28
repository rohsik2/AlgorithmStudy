#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  cout << fixed;
  cout.precision(10);
  int n_case;
  cin>>n_case;
  while(n_case--){

  int n_data;
  cin>>n_data;
  vector<pair<int,int>> v;
  vector<int> choose;
  while(n_data--){
    int a, b;
    cin>>a>>b;
    v.push_back({a,b});
  }
  for(int i = 0; i<v.size()/2; i++){
    choose.push_back(0);
  }
  for(int i = 0; i<v.size()/2; i++){
    choose.push_back(1);
  }
  double small = 987654321;
  do{
    double x = 0;
    double y = 0;
    for(int i =0; i<v.size(); i++){
      if(choose[i] == 1){
        x += v[i].first;
        y += v[i].second;
      }
      else{
        x -= v[i].first;
        y -= v[i].second;
      }
    }
    small = min(small, sqrt(x*x + y*y));
  }while(next_permutation(choose.begin(), choose.end()));
  cout<<small<<'\n';
  
  }
  return 0;
}