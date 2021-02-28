// Example program
#include <iostream>
#include <algorithm>
#include <vector>
typedef unsigned long long int ll; 
#include<math.h>
using namespace std;

int main(){
  
	cin.tie(NULL);
	ios::sync_with_stdio(false);
  ll n_tree, n_target;
  vector<ll> nums;
  cin>>n_tree >> n_target;
  while(n_tree--){
    ll temp;
    cin>>temp;
    nums.push_back(temp);
  }
  sort(nums.begin(), nums.end());
  int cnt = 1;
  int cut = 0;
  auto walker = nums.end()-1;
  int height = *walker;

  while(walker != nums.begin()){
    walker--;
    if(height == *walker){
      cnt++;
      continue;
    }
    cut += cnt*(height - *walker);
    height = *walker;
    
    if(cut > n_target){
      break;
    }
    cnt++;
  }
  if(cut < n_target){
    height -= ceil((double)(n_target-cut) /(double)cnt)-1;
  }
  while(cut >= n_target){
    height++;
    cut -= cnt;
  }
  cout<<height-1;
}