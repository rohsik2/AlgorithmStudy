#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int,int>> v;

int main() {
  int n_hist;
  cin>>n_hist;
  while(n_hist--){
    int width, height;
    cin>>height;
    if(true){
      v.push_back({1, height});
    }
  }
  
  /*
  for(int i = v.size()-1; i>0; i--){
    v[i].first = v[i].first - v[i-1].first;
  }
  */

  vector<pair<int,int>> v2;
  int max_size = -1;
  for(auto & hist : v){
    int w = 0;
    while(!v2.empty() && v2.back().second >= hist.second){
      w += v2.back().first;
      max_size = max(max_size, w * v2.back().second);
      v2.pop_back();
    }
    v2.push_back({hist.first+w, hist.second});
    
  }
  int w= 0;
  reverse(v2.begin(), v2.end());
  for(auto &hist : v2){
    w+= hist.first;
    max_size = max(max_size, w*hist.second);
  }
  cout<<max_size<<endl;

}