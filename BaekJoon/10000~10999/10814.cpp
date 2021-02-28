#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
bool compare_str(const pair<int,string>& a, const pair<int,string>& b){
  return a.first < b.first;
}

int main(){
  int n_word;
  cin >> n_word;
  vector<pair<int, string>> v;
  for(int i =0; i<n_word; i++){
    int age;
    string name;
    cin>>age>>name;
    v.push_back(make_pair(age,name));
  }
  stable_sort(v.begin(), v.end(), compare_str);
  for(vector<pair<int,string>>::iterator it = v.begin(); it != v.end(); it++){
    cout<<it->first<<" "<<it->second<<"\n";
  }
  return 0;
}