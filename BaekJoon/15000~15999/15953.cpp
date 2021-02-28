#include<iostream>
#include<vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int money1[22] = {0,500,300,300,200,200,200,50,50,50,50,30,30,30,30,30,10,10,10,10,10,10};
    int money2[32] = {0,512,256,256,128,128,128,128,64,64,64,64,64,64,64,64,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32};
    int n_q;
    cin>>n_q;
    while(n_q--){
        int a,b;
        cin>>a>>b;
        int result = 0;
        if(a<=21)
            result += money1[a]*10000;
        if(b<=31)
            result += money2[b]*10000;
        cout<<result<<'\n';
    }
    return 0;
}