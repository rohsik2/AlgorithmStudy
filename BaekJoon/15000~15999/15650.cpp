#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
//Choose M from N
void track_back(int N, int M, string current){
  if(current.length() == M){
    for(char a : current){
      cout<<a<<" ";
    }
    cout<<"\n";
  }
  if (current.length() == 0){
    for(int i = 1; i < N+1; i++){
    if(current.find((char)(i + 48)) == string::npos)
      track_back(N,M,current + (char)(i + 48));
    }
  }
  else
    for(int i = 1; i < N+1; i++){
      if(current[current.length()-1] < (char)(i+48))
        track_back(N,M,current + (char)(i + 48));
    }
  
}

int main(){
  int N, M;
  cin >> N >> M;
  track_back(N,M,"");
  return 0;
}