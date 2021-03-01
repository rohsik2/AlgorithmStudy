#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define flow_size 402

vector<int> graph[flow_size];

int capacity[flow_size][flow_size];
int flow[flow_size][flow_size];

void init(){
    for(int i = 0; i<flow_size; i++){
        for(int j = 0;j<flow_size; j++){
            capacity[i][j] = 0;
            flow[i][j] = 0;
        }
    }

    for(int i=1; i<201; i++){
        graph[0].push_back(i);
        capacity[0][i] = 1;
    }
    for(int i=201; i<401; i++){
        graph[i].push_back(401);
        capacity[i][401] = 1;
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    init();

    int n_cow, n_house, strt = 0, dest = 401;
    cin >> n_cow >> n_house;

    
    for(int i=1; i<=n_cow; i++){
        int n_want;
        cin>>n_want;
        for(int j =0; j<n_want; j++){
            int house_num;
            cin>>house_num;
            house_num+=200;
            
            graph[i].push_back(house_num);
            capacity[i][house_num] = 1;
            
            graph[house_num].push_back(i);
            capacity[house_num][i] = 0;
        }
    }

    int result = 0;

    while(true){
        queue<int> q;
        q.push(strt);
        int prev[flow_size];
        for(int i=0; i<flow_size; i++){
            prev[i] = -1;
        }
        while(!q.empty()){
            int cur = q.front();
            for(auto& next : graph[cur]){
                if(prev[next] == -1 
                    && capacity[cur][next] > flow[cur][next]){
                    prev[next] = cur;
                    q.push(next);
                    if(prev[dest] != -1)
                        break;
                }
            }
            if(prev[dest] != -1)
                break;
            q.pop();
        }
        if(prev[dest] == -1)
            break;

        int max_flow = 987654321;
        for(int cur = dest; cur != strt; cur = prev[cur]){
            max_flow = min(capacity[prev[cur]][cur] - flow[prev[cur]][cur], max_flow);
        }
        for(int cur = dest; cur != strt; cur = prev[cur]){
            flow[prev[cur]][cur] += max_flow;
            flow[cur][prev[cur]] -= max_flow;
        }
        result += max_flow;
    }
    cout<<result;
    return 0;
}