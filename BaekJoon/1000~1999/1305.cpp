#include <iostream>
#include <string>
using namespace std;

int large;

int p[1000001];
void getPi(string str){
  int s = str.size();
  int j = 0;
  for(int i =1 ; i<s; i++){
    while(j > 0 && str[i] != str[j]){
      j = p[j-1];
    }
    if(str[i] ==str[j])
    {
      p[i] = ++j;
      large = max(large, p[i]);
    }
  }
}

int main() {
  for(int i = 0; i<1000001; i++){
      p[i] = 0;
  }
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int len;
  cin>>len;
  string str;
  cin>>str;
  getPi(str);
  cout<<len-p[str.size()-1];
  return 0;
}