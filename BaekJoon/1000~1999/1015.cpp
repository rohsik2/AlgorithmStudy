#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int,int>> v;

bool comp(pair<int,int> &a, pair<int,int>& b){
  if(a.first == b.first)
    return a.second < b.second;
  return a.first < b.first;
  
  }

int main(){
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  int n_data;
  cin>>n_data;
  v.resize(n_data);
  for(int i =0 ;i<n_data; i++){
    cin>>v[i].first;
    v[i].second = i;
  }
  sort(v.begin(), v.end(), comp);
  vector<int> result;
  result.resize(n_data);
  for(int i =0; i<n_data; i++){
    result[v[i].second] = i;
  }
  for(auto& walker : result)
    cout<<walker<<' ';
  return 0;
}