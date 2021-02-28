#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int main() {
  unsigned long long int target;
  cin >> target;
  unsigned long long int cnt = 1;
  vector<unsigned long long int> nums;
  nums.clear();
  while(cnt <= target){
    nums.push_back(cnt);
    cnt = cnt*5 +1;
  }
  cnt = 0;
  while(target != 0){
    unsigned long long int dev = nums.back();
    nums.pop_back();
    cnt += pow(5,nums.size()) * (target / dev);
    if(target/dev == 5){
      cout<<"-1"<<endl;
      return 0;
    }
    target = target % dev;
  }
  cout<<cnt*5<<endl;
  return 0;
}