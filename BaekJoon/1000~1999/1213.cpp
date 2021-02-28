#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int arr[26];

int main() {
  string input;
  cin>>input;
  for(int i =0 ; i<input.size(); i++)
    arr[input[i]-'A']++;
  
  string result="";
  int idx_hansoo = -1;
  bool sorry_hansoo = false;
  for(int i =0; i<26; i++){
    if(arr[i]%2 == 1){
      if(sorry_hansoo){
        cout<<"I'm Sorry Hansoo";
        return 0;
      }
      sorry_hansoo = true;
      idx_hansoo = i;
    }
    for(int j =0; j<arr[i]/2; j++){
      result += 'A'+i;
    }
  }
  cout<<result;
  if(sorry_hansoo)
    cout<<char('A'+idx_hansoo);
  reverse(result.begin(), result.end());
  cout<<result;
  return 0;
}