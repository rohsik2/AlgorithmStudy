#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

bool sortbyxy(const pair<int, int>&a, const pair<int,int>&b){
  if(a.first < b.first)
    return true;
  else if(a.first == b.first && a.second < b.second)
    return true;
  return false;
}
int main() {
  int a;
  cin >> a;
  vector<pair<int,int>> v;
  int tmp1,tmp2;
  for (int i = 0; i<a; i++){
    cin >> tmp1 >> tmp2;
    v.push_back(make_pair(tmp1, tmp2));
  }
  sort(v.begin(),v.end(),sortbyxy);

  for(pair<int,int> p : v){
    cout<<p.first<<" "<<p.second<<"\n";
  }
}