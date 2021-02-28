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
        result.push_back(-tmp);
    }
    lcs.push_back(result[0]);
    for(int i =1; i<tmp2; i++){
        int idx = lower_bound(lcs.begin(), lcs.end(), result[i]) - lcs.begin();
        if(result[i] == lcs[idx]){
            continue;
        }
        else{
            if(idx != lcs.size())
                lcs[idx] = result[i];
            else
                lcs.push_back(result[i]);
        }
    }
    cout<<lcs.size();

    return 0;
}