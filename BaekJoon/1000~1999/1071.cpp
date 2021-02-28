#include <iostream>
#include <vector>

using namespace std;

int nums[1001];
int n;

bool BFS(vector<int>& data){
  if(data.size() == n)
    return true;
  for(int i =0; i<1001; i++){
    if(data.empty() && nums[i]>0){
      data.push_back(i);
      nums[i]--;
      if(BFS(data))
        return true;  
      data.pop_back();
      nums[i]++;
      continue;
      }
    if(nums[i] > 0 && data.back()+1 != i){
      data.push_back(i);
      nums[i]--;
      if(BFS(data))
        return true;
      data.pop_back();
      nums[i]++;
    }
  }
  return false;
}

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  for(int i =0; i<1001; i++)
  {
    nums[i] = 0;
  }
  cin>>n;
  for(int i = 0; i<n; i++){
    int temp;
    cin>>temp;
    nums[temp]++;
  }
  vector<int> v;
  BFS(v);
  for(auto& walker : v){
    cout<<walker<<' ';
  }
  return 0;
}