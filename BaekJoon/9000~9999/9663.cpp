#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
//Choose M from N

int CNT = 0;

void track_back(int N, string m){
  if(m.length() > 1){
    //check left-up cross
    for(int i =1; i<m.length(); i++){
      if((int)m[m.length()-1-i] == (int)(m[m.length()-1])-i)
        return;
    }
    //check right-up cross
    for(int i =1; i<m.length(); i++){
      if((int)m[m.length()-1-i] == (int)(m[m.length()-1])+i)
        return;
    }
    if(m.length() == N){
      CNT++;
      return;
    }
  }
  bool done = false;
  for(int i = 0 ; i<N; i++){
    if(m.find((char)(i+48)) == string::npos){
      track_back(N, m + (char)(i+48));
    }
  }
    
}

int main(){
  int N;
  cin >> N;
  if(N==1)
    cout<<1;
  else if(N==2)
    cout<<0;
  else{
    track_back(N,"");
    cout<<CNT<<endl;
  }
  
  return 0;
}