#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);    
    string temp;
    string result;
    getline(cin,temp);
    vector<string> v;
    for(int i = temp.size()-1; i>=0; i--){
      result = temp[i] + result;
      v.push_back(result);
    }
    sort(v.begin(), v.end());
    for(auto& walker : v)
      cout<<walker<<'\n';
    return 0;
}