#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1987654321
using namespace std;
vector<int> moneys;
int DP[100001];

queue<pair<int, int>> q; 
int main() {
    int n_money, target;
    cin>>n_money>>target;
    for(int i =0; i<100001; i++){
        DP[i] = INF;
    }
    while(n_money--){
        int temp;
        cin>>temp;
        if(temp <= target && DP[temp] == INF ){
            moneys.push_back(temp);
            DP[temp] = 1;
            q.push({1,temp});
        }
    }
    sort(moneys.begin(), moneys.end());
    while(!q.empty() && DP[target] == INF && q.front().second < target+moneys[moneys.size()-1]){
        for(int money : moneys){
            if(q.front().second <= target && DP[q.front().second + money] == INF){
                DP[q.front().second+money] = q.front().first+1;
                q.push({q.front().first+1, q.front().second+money});
            }
        }
        q.pop();
    }
    /*
    for(int i =0; i<=target; i++)
        cout<<DP[i]<< ' ';
*/
    if(DP[target] == INF)
        cout<<"-1";
    else
        cout<<DP[target];
    

}