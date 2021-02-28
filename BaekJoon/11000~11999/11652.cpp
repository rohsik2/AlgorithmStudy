#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n_card;
    cin>>n_card;
    vector<long long> nums;
    while(n_card--){
        long long temp;
        cin>>temp;
        nums.push_back(temp);
    }
    sort(nums.begin(), nums.end());
    long long large =1;
    long long cnt = 0;
    long long large_num = nums[0];
    long long prev_num = nums[0];
    for(long long& walker : nums){
        if(prev_num == walker){
            cnt++;
            if(large < cnt){
                large = cnt;
                large_num = walker;
            }
        }
        else
            cnt = 1;
        prev_num = walker;
    }
    cout<<large_num;
    return 0;
}