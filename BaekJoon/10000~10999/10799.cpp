#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  string str;
  cin>>str;
  int cnt = 0;
  int result = 0;
  for(int i =0 ;i<str.size(); i++){
    if(str[i] == '('){
      result+=1;
      cnt++;
    }
    else if(str[i-1] == '('){
      result-=1;
      result += --cnt;
    }
    else
      cnt--;
  }
  cout<<result;
  return 0;
}