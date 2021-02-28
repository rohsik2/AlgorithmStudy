#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
// x 좌표 기준으로 정렬
// y 좌표 기준으로 정렬
//priority queue에 인접한 두 점을 잇는 간선길이로 정렬 되게 넣는다.
//query를 health순으로 정렬
//각각의 health미만의 길이를 가진 간선들은 union으로 묶어준다..
//union find로 조지기.


int parent[250002];
string query_result[250002];
vector<pair<int,int>> points;

vector<pair<pair<int,int>,int>> querys;

bool comp_x(pair<int, pair<int,int>>& a, pair<int, pair<int,int>>& b){
    if(a.second.first == b.second.first)
        return a.second.second < b.second.second;
    return a.second.first < b.second.first;
}

bool comp_y(pair<int,pair<int,int>>& a, pair<int,pair<int,int>>& b){
    if(a.second.second == b.second.second)
        return a.second.first < b.second.first;
    return a.second.second < b.second.second;
}

int get_p(int child){
    if(parent[child] == -1)
        return child;
    return parent[child] = get_p(parent[child]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i =0 ;i<250002; i++) query_result[i] = parent[i] = -1;


    int n_point, n_query;
    cin>>n_point>>n_query;


    //{idx , {x, y}}
    vector<pair<int,pair<int,int>>> idx_points;
    idx_points.reserve(n_point);
    for(int i = 0; i<n_point; i++){
        int x, y;
        cin>>x>>y;
        points.push_back({x,y});
        idx_points.push_back({i,{x,y}});
    }

    //dist, {strt_idx, end_idx}
    priority_queue<pair<int, pair<int,int>>> dists;

    sort(idx_points.begin(), idx_points.end(), comp_x);
    
    for(int i = 1; i<idx_points.size(); i++){
        int dist = idx_points[i].second.first - idx_points[i-1].second.first;
        int idx1 = idx_points[i].first;
        int idx2 = idx_points[i-1].first;
        dists.push({-dist, {idx1, idx2}});
    }
    
    sort(idx_points.begin(), idx_points.end(), comp_y);
    
    for(int i = 1; i<idx_points.size(); i++){
        int dist = idx_points[i].second.second - idx_points[i-1].second.second;
        int idx1 = idx_points[i].first;
        int idx2 = idx_points[i-1].first;
        dists.push({-dist, {idx1, idx2}});
    }


    // health, {query_num , {strt, dest}}
    priority_queue<pair<int, pair<int, pair<int,int>>>> querys;
    for(int i = 0; i<n_query; i++){
        int strt, dest, health;
        cin>>strt>>dest>>health;
        querys.push({-health, {i, {strt-1, dest-1}}});
    }

    while(!querys.empty()){
        auto query = querys.top();
        int health = query.first;
        int q_num = query.second.first;
        int strt = query.second.second.first;
        int dest = query.second.second.second;
        while(!dists.empty() && -(dists.top().first) <= -health){
            auto point = dists.top().second;
            int x= point.first;
            int y = point.second;
            int p_x = get_p(x);
            int p_y = get_p(y);
            if(p_x == p_y){
                ;
            }
            else if (p_x < p_y){
                parent[p_y] = p_x;
            }
            else {
                parent[p_x] = p_y;
            }
            dists.pop();
        }
        if(get_p(strt) == get_p(dest)){
            query_result[q_num] = "YES"; 
        }
        else
            query_result[q_num] = "NO";
        querys.pop();
    }
    for(int i = 0; i<n_query; i++){
        cout<<query_result[i]<<'\n';
    }
    return 0;
}