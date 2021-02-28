#include<iostream>

using namespace std;
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int a,b;
    cin>>a>>b;
    for(int i =0; i<a; i++){
        int temp;
        cin>>temp;
        if(temp < b){
            cout<<temp<<" ";
        }
    }
    return 0;
}
