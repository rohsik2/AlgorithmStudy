#include <iostream>
#include <vector>

using namespace std;

int carry;    
vector<int> v;
vector<int> acc;

int dp[3][50001];

int solve(int used, int cur){
    if(cur < carry){
        return dp[used][cur] = acc[cur];
    }
    if(dp[used][cur] != -1)
        return dp[used][cur];
    if(used == 0){
        return dp[used][cur] = max(solve(0, cur-1), acc[cur] - acc[cur-carry]);
    }
    else if(used == 1){
        if(cur < carry*2){
            return dp[used][cur] = acc[cur];
        }
        return dp[used][cur] = max(solve(1, cur-1), solve(0,cur-carry) + acc[cur] - acc[cur-carry]);
    }
    else{
        if(cur < carry*3){
            return dp[used][cur] = acc[cur];
        }
        return dp[used][cur] = max(solve(2, cur-1),solve(1, cur-carry) + acc[cur] - acc[cur-carry]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    for(int j = 0; j<3; j++)
        for(int i =0 ;i<50001; i++)
            dp[j][i] = -1;
    int n;
    cin>>n;
    for(int i = 0; i<n; i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    cin>>carry;

    int temp = 0;
    for(int i =0 ;i<n; i++){
        temp += v[i];
        acc.push_back(temp);
    }
    cout<<solve(2, n-1);
    
    /*for(int j =0; j<3; j++)
    {
        for(int i =0 ;i<n; i++)
            cout<<dp[j][i]<<' ';
        cout<<endl;
        }*/
}