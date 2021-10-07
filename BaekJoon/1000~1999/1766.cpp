#include <iostream>
#include <queue>

using namespace std;

vector<int> next_prob[32001];
vector<int> prev_prob[32001];
int cnt[320001];
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n_prob, n_query;
    cin>>n_prob>>n_query;
    for(int i =0;i<n_query; i++){
        int a,b;
        cin>>a>>b; 
        next_prob[a].push_back(b);
        prev_prob[b].push_back(a);
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i =1; i<=n_prob; i++){
        cnt[i] = prev_prob[i].size();
        if(prev_prob[i].size() == 0)
            pq.push(i);
    }
    while(!pq.empty()){
        int cur = pq.top();
        pq.pop();
        for(auto& next : next_prob[cur]){
            cnt[next]--;
            if(cnt[next]==0)
                pq.push(next);
        }
        cout<<cur<<' ';
    }
    return 0;
}