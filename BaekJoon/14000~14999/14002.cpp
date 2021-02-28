#include <iostream>
#include <vector>

using namespace std;

int prev_idx[1001];

int main() {
    ios::sync_with_stdio(false);
    for(int i =0 ;i<1001; i++)
        prev_idx[i] = -1;
    int n;
    cin>>n;
    vector<int> v;
    v.resize(n);
    for(int i =0 ;i<n; i++){
        cin>>v[i];
    }


    vector<pair<int,int>> stk;
    stk.push_back({-1,-1});
    for(int i = 0; i<n; i++){
        if(stk.back().first < v[i]){
            prev_idx[i] = stk.back().second;
            stk.push_back({v[i],i});
        }
        else{
            for(int k = stk.size()-1; k>0; k--){
                if(stk[k-1].first < v[i]){
                    stk[k].first = v[i];
                    prev_idx[i] = stk[k-1].second;
                    stk[k].second = i;
                    break;
                }
            }
        }
    }
    
    cout<<stk.size()-1<<'\n';
    int cur = stk.back().second;
    vector<int> result;
    while(cur != -1){
        result.push_back(v[cur]);
        cur = prev_idx[cur];
    }
    for(int i = result.size()-1; i>=0; i--)
        cout<<result[i]<<' ';
    return 0;
}
