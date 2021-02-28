#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  int n_case;
  cin>>n_case;
  while(n_case--){
    string temp;
    cin>>temp;
    bool possible = true;
    
    for(int i = 0; i<temp.size(); i++){
      if(!possible)
        break;
      
      if(temp[i] == '0' && i+1 < temp.size() && temp[i+1] != '1'){
        if(temp[i-1] == '1' && temp[i-2] == '1' ){
          i-=2;
          continue;
        }
          possible = false;
          break;
      }
      
      else if(temp[i] == '0' && i+1 < temp.size() && temp[i+1] == '1'){
        i=i+1;
        continue;
      }

      if(temp.size() >= i+4 && temp[i] == '1' && temp[i+1] == '0' && temp[i+2] == '0'){
        i = i+2;
        while(i<temp.size() && temp[i] == '0')
          i++;
        if(i == temp.size())
        {
          possible = false;
          break;
        }
        while(i+1<temp.size() && temp[i+1] == '1'){
          i++;
        }
        if(temp[i] != '1'){
          possible = false;
          break;
        }
      }
      else{
        possible = false;
        break;
      }
      if(!possible)
        break;
    }
    if(possible)
      cout<<"YES\n";
    else
      cout<<"NO\n";
  }
  return 0;
}