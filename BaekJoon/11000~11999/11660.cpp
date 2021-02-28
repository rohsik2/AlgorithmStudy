#include<iostream>
#include<vector>

using namespace std;

int nums[1026][1026];
int dp[1026][1026];

int main(){
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  int x,n;
  cin>>x>>n;
  for(int i=1; i<=x; i++){
    for(int j =1; j<=x; j++){
      cin >> nums[i][j];
      if(i==0&&j==0){
        dp[i][j] = nums[i][j];
      }
      else if(i==0 && j>0)
        dp[i][j] = dp[i][j-1] + nums[i][j];
      else if(j==0){
        dp[i][j] = dp[i-1][j]+nums[i][j];
      }
      else{
        dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + nums[i][j];
      }
    }
  }
  
  for(int i=0; i<=1026; i++){
    dp[i][0] = 0;
    dp[0][i] = 0;
    nums[i][0] = 0;
    nums[0][i] = 0;
  }


  while(n--){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    cout<<dp[c][d] + dp[a-1][b-1] - dp[a-1][d] - dp[c][b-1]<<'\n'; 
  }
  return 0;

  
}