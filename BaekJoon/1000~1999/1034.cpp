/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    vector<pair<string,int>> v;
    for(int i =0 ; i<n; i++){
        string temp;
        cin>>temp;
        bool is_dup = false;
        for(int j  =0; j<v.size(); j++){
            if(v[j].first.compare(temp) == 0){
                v[j].second++;
                is_dup = true;
                break;
            }
        }
        if(!is_dup)
            v.push_back({temp, 1});
    }
    int k;
    cin>>k;
    int best = 0;
    for(int i = 0; i<v.size(); i++){
        int cnt = 0;
        for(int j =0; j<m; j++){
            if(v[i].first[j] == '0') cnt++;
        }
        if(cnt <= k && ((k-cnt) % 2 == 0)){
            best = max(best, v[i].second);
        }
    }
    cout<<best;
    return 0;
}
