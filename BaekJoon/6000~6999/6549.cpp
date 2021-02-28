#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  while(true){

    long long int n_hist;
    cin>>n_hist;
    if(n_hist == 0) return 0;

    vector<pair<long long int, long long int>> hists; // heights, width
    long long int large = -1;
    while(n_hist--){
      long long int temp;
      cin>>temp;
      long long int cnt = 0;
      while(true){
        /*
        for(auto& walker : hists)
          cout<<walker.first<<' ';
        cout<<endl;
        */
        pair<long long int, long long int>* top = &hists[hists.size()-1];
        if(hists.size() == 0 || top->first < temp){
          hists.push_back({temp,cnt+1});
          break;
        }
        else if(top->first == temp ){
          top->second += (cnt+1);
          break;
        }
        else{
          if(hists.size() > 1 && top->first > temp){
            large = max(large, top->first * (top->second + cnt));
            cnt += top->second;
            hists.pop_back();
          }
          else
            if(hists.size()==1){
              large = max(large, top->first * (top->second + cnt));
              cnt += top->second;
              hists.pop_back();
            }
        }
      }
    }
    while(hists.size() > 1){
      pair<long long int, long long int>* top = &hists[hists.size()-1];
      large = max(large, top->first * top->second);
      hists[hists.size()-2].second += top->second;
      hists.pop_back();
    }
    large = max(large, hists[0].first * hists[0].second);
    cout<<large<<endl;
  }
}