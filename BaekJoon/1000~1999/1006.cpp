#include<iostream>
#include<vector>

using namespace std;

int n_place, n_soldier;
vector<int> board0;
vector<int> board1;
int dp1[10001],dp2[10001], dp3[10001];

int result;

void print(){
  cout<<result<<'\n';
  for(int i =0 ;i<n_place+1; i++)
    cout<<dp1[i]<<' ';
  cout<<endl;
  for(int i =0 ;i<n_place+1; i++)
    cout<<dp2[i]<<' ';
  cout<<endl;
  for(int i =0 ;i<n_place+1; i++)
    cout<<dp3[i]<<' ';
  cout<<endl;
}

int solve1(int);
int solve3(int);
int solve2(int);

void init(){
  for(int i =0; i<10001; i++){
    dp1[i] = -1;
    dp2[i] = -1;
    dp3[i] = -1;
  }
}

int solve1(int cur){
  if (cur<=0)
    return 0;
  if(dp1[cur] != -1)
    return dp1[cur];
  //가로로 두개가 붙을 경우
  int temp = 987654321;
  if (cur >= 2){
    if(n_soldier >= board0[cur-1] + board0[cur-2] && n_soldier >= board1[cur-1] + board1[cur-2])
    temp = solve1(cur-2) + 2;
  }
  if(n_soldier < board0[cur-1] + board1[cur-1])
    return dp1[cur] = min(temp, min(solve2(cur)+1, solve3(cur)+1));
  else{
    return dp1[cur] = min(min(solve2(cur)+1, solve3(cur)+1), min(solve1(cur-1)+1,temp));
  }

}

int solve2(int cur){
  if(cur<=0)
    return 0;
  if(dp2[cur] != -1)
    return dp2[cur];
  return dp2[cur] = min(solve1(cur-1) + 1, solve3(cur-1) + (board0[cur-1]+board0[cur-2]<=n_soldier ? 1: 2)); 
}

int solve3(int cur){
  if(cur<=0)
    return 0;
  if(dp3[cur] != -1)
    return dp3[cur];
  return dp3[cur] = min(solve1(cur-1) +1, solve2(cur-1) + (board1[cur-1]+board1[cur-2]<=n_soldier ? 1: 2)); 
  
}


int main(){
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  int n_test;
  cin>>n_test;
  while(n_test--){
    board0.clear();
    board1.clear();
    cin>>n_place>>n_soldier;
    board0.resize(n_place);
    board1.resize(n_place);
    
    for(int i =0; i<n_place; i++){
      cin >> board0[i];
    }

    for(int i =0; i<n_place; i++){
      cin >> board1[i];
    }


    init();
    result = solve1(n_place);
    //print();
    if(n_place > 1){
    //두개다 마지막에 겹쳤을때
    if(board0.front() + board0.back() <= n_soldier && board1.front() + board1.back() <= n_soldier){
      init();
      int tempa = board0[0], tempb = board1[0];
      board0[0] = n_soldier+1;
      board1[0] = n_soldier+1;
      int a= solve1(n_place-1);
      result = min(result, a);
      board0[0] = tempa;
      board1[0] = tempb;
    }
    if(board0[0] + board0[board0.size()-1] <= n_soldier){
      init();
      int tempa = board0[0], tempb = board1[0];
      board0[0] = n_soldier+1;
      int a= solve3(n_place);
      result = min(result, a);
      board0[0] = tempa;
      //print();
    }
    //아래꺼만 겹쳤을때
    if(board1.front() + board1.back()  <= n_soldier){
      init();
      int tempa = board0[0], tempb = board1[0];
      board1[0] = n_soldier+1;
      int a= solve2(n_place);
      result = min(result, a);
      board1[0] = tempb;
      //print();
    }}
    cout<<result<<'\n';
  }
  return 0;
}