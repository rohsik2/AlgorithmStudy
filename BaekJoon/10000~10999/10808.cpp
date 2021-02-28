#include<iostream>
#include<string>

using namespace std;
int cnt[26];

int main(){
    for(int i =0 ; i<26; i++){
        cnt[i] = 0;
    }
    string temp;
    cin>>temp;
    for(int i =0; i<temp.size(); i++){
        cnt[int(temp[i]) - 97]+=1;
    }
    for(int i =0; i<26; i++)
        cout<<cnt[i]<<' ';
    return 0;
}