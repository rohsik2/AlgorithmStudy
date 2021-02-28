#include<iostream>
#include<string>

using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);    
    string temp;
    string result;
    getline(cin,temp);
    for(int i = 0; i<temp.size(); i++){
      if(temp[i]<='m' && temp[i]>='a'){
        result += 13+temp[i];
      }
      else if(temp[i]>'m' && temp[i]<='z'){
        result += temp[i]-13;
      }
      else if(temp[i]<='M' && temp[i]>='A'){
        result += 13+temp[i];
      }
      else if(temp[i]>'M' && temp[i]<='Z'){
        result += temp[i]-13;
      }
      else
        result += temp[i];
    }
    cout<<result;
    return 0;
}