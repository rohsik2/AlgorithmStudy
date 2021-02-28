#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> graph[200];

int capacity[200][200];
int flow[200][200];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i=0; i<200*200; i++){
        capacity[i/200][i%200] = flow[i/200][i%200] = 0;    
    }
    int n_pipe;
    cin>>n_pipe;
    for(int i=0; i<n_pipe; i++){
        char a, b;
        int weight;
        cin>>a>>b>>weight;
        graph[a].push_back(b);
        graph[b].push_back(a);
        capacity[a][b] += weight;
        capacity[b][a] += weight;
    }
    int total = 0;
    while(1){
        queue<int> q;
        q.push('A');
        int prev[200];
        for(int i =0 ;i<200; i++) prev[i] = -1;
        prev['A'] = 'A';
        while(!q.empty()){
            int cur = q.front();
            if(cur == 'Z')
                break;
            for(auto& next : graph[cur]){
                if(prev[next] == -1 && capacity[cur][next] > flow[cur][next]){
                    q.push(next);
                    prev[next] = cur;
                }
            }
            q.pop();
        }
        if(prev['Z'] == -1)
            break;
        int maxflow = 1987654321;
        for(int cur='Z'; cur!='A'; cur=prev[cur]){
            maxflow = min(maxflow, capacity[prev[cur]][cur] - flow[prev[cur]][cur]);
        }
        for(int cur='Z'; cur!='A'; cur=prev[cur]){
            flow[prev[cur]][cur] += maxflow;
            flow[cur][prev[cur]] -= maxflow;
        }
        total += maxflow;
    }
    cout<<total;
}