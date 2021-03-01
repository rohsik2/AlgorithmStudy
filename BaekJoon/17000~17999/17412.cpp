#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[401];

int capacity[401][401];
int flow[401][401];

void init(){
    for(int i = 0; i<401; i++){
        for(int j = 0;j<401; j++){
            capacity[i][j] = 0;
            flow[i][j] = 0;
        }
    }
}

int main() {
    init();

    int n_v, n_e, strt = 1, dest = 2;
    cin >> n_v >> n_e;

    //주의! 단방향이라도 반대방향으로 capacity = 0인 간선을 넣어주어야함.
    for(int i=0; i<n_e; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        capacity[a][b] = 1;
        graph[b].push_back(a);
        capacity[b][a] = 0;
    }

    int result = 0;

    while(true){
        queue<int> q;
        q.push(strt);
        int prev[401];
        for(int i=0; i<401; i++){
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
