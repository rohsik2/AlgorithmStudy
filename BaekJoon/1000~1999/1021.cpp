#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;
int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  int n_num, n_target;
  cin>>n_num>>n_target;
  deque<int> dq;
  for(int i = 1; i<=n_num; i++){
    dq.push_back(i);
  }
  int result = 0;
  while(n_target--){
    int target;
    cin>>target;
    int cnt = 0;
    while(dq.front() != target){
      dq.push_back(dq.front());
      dq.pop_front();
      cnt++;
    }
    result+= cnt> dq.size()-cnt ? dq.size()-cnt : cnt;
    dq.pop_front();
  }
  cout<<result;
  return 0;
}