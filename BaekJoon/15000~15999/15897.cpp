#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int main() {
  unsigned long long int num;
  cin>>num;  
  vector<unsigned long long int> v;
  for(int i = 1; i <= ceil(sqrt(num))-1; i++){
    v.push_back(i);
    if(num % i == 0)
      v.push_back(num/i);
    else
      v.push_back(num/i + 1);
  }
  v.push_back(ceil(sqrt(num)));
  v.push_back(num+1);
  sort(v.begin(), v.end());
  unsigned long long int cnt = 0;
  for(int i = 0; i<v.size()-1; i++){
    cnt += (v[i+1] - v[i]) * (ceil((double)num/(double)v[i]));
  }
  cout<<cnt;
}