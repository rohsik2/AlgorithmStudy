#include<iostream>
using namespace std;
int main(){
    int num;
    cin>>num;
    int ans = 1;
    while(num--){
        int a,b;
        cin>>a>>b;
        if(a == ans){
            ans = b;
            continue;
        }
        if(b == ans){
            ans = a;
            continue;
        }
    }
    cout<<ans;
}