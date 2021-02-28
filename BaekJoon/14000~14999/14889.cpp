#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> stats;
int n_people;
int sum = 0;

int delta = 987654321;

int get_stat(int x, int y){
  return stats[x*n_people + y];
}

int score(vector<int> chosen){
  int result = 0;
  for(int i  = 0; i< chosen.size(); i++){
    for(int j  = 0; j< chosen.size(); j++){
      result += get_stat(chosen[i],chosen[j]);
    }
  }
  return result;
}
int score2(vector<int> chosen){
  vector<int> peoples;
  int result = 0;
  for(int i =0; i<n_people; i++){
    if(find(chosen.begin(), chosen.end(),i) == chosen.end())
    peoples.push_back(i);
  }
  for(int i  = 0; i< chosen.size(); i++){
    for(int j  = 0; j< chosen.size(); j++){
      result += get_stat(peoples[i],peoples[j]);
    }
  }
  return result;
}

void back_track(vector<int> chosen, int idx){
  if(idx > n_people)
    return;
  if(chosen.size() == n_people/2){
    delta = min(delta, abs(score(chosen) - score2(chosen)));
    return;
  }
  chosen.push_back(idx);
  back_track(chosen,idx+1);
  chosen.pop_back();
  back_track(chosen, idx+1);
}

int main() {
  cin>>n_people;
  for(int i =0; i<n_people; i++){
    for(int j = 0; j<n_people; j++){
      int tmp;
      cin >> tmp;
      stats.push_back(tmp);
      sum += tmp;
    }
  }
  vector<int> chosen;
  back_track(chosen, 0);
  cout<<delta;
  return 0;
}