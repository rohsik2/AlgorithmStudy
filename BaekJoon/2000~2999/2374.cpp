#include <iostream>
#include <vector>

using namespace std;

vector<long long> nums;

long long cur = 0;

long long make_same(long long strt, long long end){
    if(strt >= nums.size())
        return 0;
    if (strt+1 == end)
        return nums[strt];
    if(strt+2 == end){
        cur += abs(nums[strt] -  nums[strt+1]);
        return max(nums[strt], nums[strt+1]);
    }
    
    long long large = -1;
    long long idx = -1;
    for(long long i = strt ; i<end; i++){
        if(nums[i] > large){
            large = nums[i];
            idx = i;
        }
    }
    if(strt < idx)
        cur += large - make_same(strt, idx);
    
    if(idx+1 < end)
        cur += large - make_same(idx+1, end);
    //cout<<strt << " : "<<end<<" : "<<cur<<endl;
    return large;
}

int main() {
    long long n_data=0;
    cin>>n_data;
    while(n_data--){
        long long temp;
        cin>>temp;
        nums.push_back(temp);
    }
    make_same(0,nums.size());
    cout<< cur;
    return 0;
}