#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int result[10];

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  for(int i =0; i<10; i++)
    result[i] = 0;
  int target;
  cin>>target;
  if(target == 0){
    cout<<1;
    return 0;}
  while(target > 0){
    result[target%10]++;
    target = target/=10;
  }

  result[6] = ceil(double(result[6]+result[9])/2.0);  
  result[9] = result[6];
  int l = -1;
  for(auto& walker : result){
    l = max(walker, l);
  }
  cout<<l;
  return 0;
}