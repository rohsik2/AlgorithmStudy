#include<iostream>
#include<string>

using namespace std;
int cnt[26];

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    string temp;
    while(getline(cin,temp)){
      int small=0;
      int big=0; 
      int num=0;
      int blank=0;
      for(int i =0 ;i<temp.size(); i++){
        if( 'a'<= temp[i] && temp[i] <= 'z')
          small++;
        if( 'A'<= temp[i] && temp[i] <= 'Z')
          big++;
        if( ' ' == temp[i])
          blank++;
        if( '0'<= temp[i] && temp[i] <= '9')
          num++;
      }
      cout<<small<<' '<<big<<' '<<num<< ' '<<blank<<'\n';
    }
    return 0;
}