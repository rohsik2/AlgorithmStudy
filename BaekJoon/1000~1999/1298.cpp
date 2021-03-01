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

    int n_person, n_laptop, strt = 0, dest = 401;
    cin >> n_person >> n_laptop;

    
    for(int i=1; i<=n_laptop; i++){
        int laptop_num;
        int person_num;
        cin>>person_num>>laptop_num;
        laptop_num+=200;
        
        graph[person_num].push_back(laptop_num);
        capacity[person_num][laptop_num] = 1;
        
        graph[laptop_num].push_back(person_num);
        capacity[laptop_num][person_num] = 0;
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