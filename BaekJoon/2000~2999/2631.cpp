#include<iostream>
#include<vector>
using namespace std;

vector<int> result;
vector<int> lcs;

int main(){
    int tmp2;
    cin>> tmp2;
    for(int i = 0; i<tmp2; i++){
        int tmp;
        cin >> tmp;
        result.push_back(tmp);
    }
    lcs.push_back(result[0]);
    for(int i =1; i<tmp2; i++){
        auto iter = lower_bound(lcs.begin(), lcs.end(), result[i]);
        if(iter == lcs.end())
            lcs.push_back(result[i]);
        else
            *iter = result[i];
    }
    cout<<tmp2 - lcs.size();

    return 0;
}