#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<long long,pair<long long,long long>> &a, pair<long long,pair<long long,long long>> &b){
    if(a.second.first == b.second.first)
        return a.second.second > b.second.second;
    return a.second.first < b.second.first;
}

bool nessesary[1000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n_bus_stop;
    long long n_bus_line;

    cin>>n_bus_stop>>n_bus_line;
    vector<pair<long long,pair<long long , long long>>> lines;
    lines.reserve(n_bus_line);
    for(long long i= 0; i<n_bus_line; i++){
        long long temp1, temp2;
        cin>>temp1 >> temp2;
        if(temp1 > temp2)
            lines.push_back({i,{temp1, temp2 + n_bus_stop}});
        else
            lines.push_back({i,{temp1, temp2}});

    }

    sort(lines.begin(), lines.end(), comp);
    
    long long front = 0;
    for(long long i=0; i<lines.size(); i++){
        nessesary[lines[i].first] = true;
        if(front >= lines[i].second.second){
            nessesary[lines[i].first] = false;
        }
        else
            front = lines[i].second.second;
    }
    for(long long i=0; i<lines.size(); i++){
        nessesary[lines[i].first+500000] = true;
        if(front >= lines[i].second.second+n_bus_stop){
            nessesary[lines[i].first+500000] = false;
        }
        else
            front = lines[i].second.second+n_bus_stop;
    
    }
    for(long long i =0; i<500000; i++){
        if(nessesary[i] && nessesary[i+500000])
            cout<<i+1<<' ';
    }
    return 0;
}