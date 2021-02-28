#include<iostream>

using namespace std;
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int num;
    cin>>num;
    int new_num = num%10*10 + (num/10 + num%10) % 10;
    int cnt = 1;
    while(num!=new_num){
        new_num = new_num%10*10 + (new_num/10 + new_num%10) % 10;
        cnt++;
    }
    cout<<cnt;
    return 0;
}