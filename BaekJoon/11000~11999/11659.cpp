#include <iostream>
#include <vector>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  int n_data, n_q;
  cin>>n_data>>n_q;
  vector<int> dp;
  dp.push_back(0);
  while(n_data--){
    int temp;
    cin>>temp;
    dp.push_back(dp[dp.size()-1]+temp);
  }
  while(n_q--){
    int strt, end;
    cin>>strt>>end;
    cout<<dp[end] - dp[strt-1]<<'\n';
  }
  return 0;
}