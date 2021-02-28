#include<iostream>
#include<vector>

using namespace std;

int parent[1000];

vector<int> get_p(int child){
  vector<int> result;
  while(child != -1){
    result.push_back(child);
    child = parent[child];
  }
  return result;
}

int main(){
  ios::sync_with_stdio(false);

  for(int i =0 ;i<1000; i++){
    parent[i] = -1;
  }

  int n_people;
  cin>>n_people;

  int target_a, target_b;
  cin>>target_a>>target_b;

  int n_rule;
  cin>>n_rule;

  while(n_rule--){
    int c,p;
    cin>>p>>c;
    parent[c] = p;
  }

  vector<int> a_parents = get_p(target_a);
  vector<int> b_parents = get_p(target_b);

  if(a_parents.back() != b_parents.back()){
    cout<<-1;
  }
  else{
    int last = -1;
    while(!a_parents.empty() && !b_parents.empty() && a_parents.back() == b_parents.back()){
      last = a_parents.back();
      a_parents.pop_back();
      b_parents.pop_back();
    }
    cout<<a_parents.size() + b_parents.size();
  }
  return 0;
}