#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n_card, n_union;
  cin>>n_card>>n_union;
  vector<unsigned long long int> nums;
  while(n_card--){
    int temp;
    cin>>temp;
    nums.push_back(temp);
  }
  while(n_union--){
    sort(nums.begin(), nums.end());
    unsigned long long int temp = nums[0] + nums[1];
    nums[0] = temp;
    nums[1] = temp;
  }
  unsigned long long int sum = 0;
  for(auto& walker : nums){
    sum += walker;
  }
  cout<<sum;
  return 0;

}