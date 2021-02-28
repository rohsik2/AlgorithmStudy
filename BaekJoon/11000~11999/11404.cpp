#include<iostream>
#define INF 1000000001
using namespace std;

int board[101][101];

void init(){
  for(int i =0 ;i<101; i++) for(int j = 0; j<101; j++){
    board[i][j] = INF;
    if(i == j) board[i][j] = 0;
  }
}
int main(){
  ios::sync_with_stdio(false);
  init();

  int n_city;
  cin>>n_city;

  int n_bus;
  cin>>n_bus;

  while(n_bus--){
    int strt, end, cost;
    cin>>strt>>end>>cost;
    board[strt][end] = min(cost, board[strt][end]);
  }
  for(int k =0 ; k<2; k++)
   for(int strt = 1; strt <= n_city; strt++){
      for(int end = 1; end <= n_city; end++){
        for(int stopover = 1; stopover<=n_city; stopover++){
   
        int best = board[strt][end];
        int strt_stopover = board[strt][stopover];
        int stopover_end = board[stopover][end];
        
        if(strt_stopover < INF && stopover_end < INF){
          best = min(best, strt_stopover + stopover_end);
          board[strt][end] = best;
        }
      }
    }
  }
  for(int i =1 ;i<=n_city; i++){
    for(int j = 1; j<=n_city; j++){
      if(board[i][j] >= INF)
        cout<<0<<' ';
      else
        cout<<board[i][j]<< ' ';
    }
    cout<<'\n';
  }
}