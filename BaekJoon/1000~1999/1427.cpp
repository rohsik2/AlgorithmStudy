#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
int main() {
  string a;
  cin >> a;
  vector<int> v;
  for(int i =0; i < a.length(); i++){
    v.push_back(((int)a[i]) - 48);
  }  
  sort(v.begin(),v.end(),greater<int>());
  for (const auto &i: v)
      cout << i;
}