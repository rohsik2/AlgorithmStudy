#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int values[10001];

vector<int> coins;
int get(int target){
  if(target == 0)
    return 1;
  if (target < 0)
    return 0;
  return values[target];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  for(int j =0; j<10001; j++)
    values[j] = 0;
  

  int n, k;
  cin>>n>>k;

  for(int i =0 ; i<n; i++){
    int temp;
    cin >> temp;
    if (temp <= 10000){
      coins.push_back(temp);
    }
  }
  sort(coins.begin(), coins.end());
  for(int i =0; i<coins.size(); i++){
    for(int j =0; j<=k; j++){
      values[j] = get(j) + get(j-coins[i]);
    }
  }

  cout<<values[k];

  return 0;
}