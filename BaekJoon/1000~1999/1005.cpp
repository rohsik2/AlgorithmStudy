#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> build_time;
vector<int> req[1001];
    
int DP[1001] = {-1,};

const bool is_big(pair<int, int>& a, pair<int, int>& b){
  if(a.first == b.first)
    return a.second < b. second;
  return a.first < b.first;
}

int calc(int target){
  if(DP[target] != -1)
    return DP[target];
  if(req[target].size() == 0)
    return DP[target] = build_time[target];
  else{
    int cnt = 0;
    for(auto& walker : req[target]){
      cnt = max(cnt, calc(walker));
    }
    return DP[target] = cnt+build_time[target];
  }
}

int main(){
  cin.tie(NULL);
	ios::sync_with_stdio(false);

  int n_case;
  cin>>n_case;
  while(n_case--){
    int n_build, n_order;
    cin>>n_build>>n_order;
    
    //init
    build_time.clear();
    for(auto& walker : req)
      walker.clear();
    for(auto& walker : DP)
      walker = -1;

    build_time.push_back(0);
    while(n_build--){
      int temp;
      cin>>temp;
      build_time.push_back(temp);
    }
    
    while(n_order--){
      int p,c;
      cin >> p >> c;
      req[c].push_back(p);
    }
    int target;
    cin>>target;
    cout<<calc(target)<<endl;
  }

  return 0;
}