#include<iostream>
using namespace std;

long long int get_zeros(long long int num){
    long long int cnt = 0;
    while(num>0){
        num /= 5;
        cnt+=num;
    }
    return cnt;
}
long long int get_zeros2(long long int num){
    long long int cnt = 0;
    while(num>0){
        num /= 2;
        cnt+=num;
    }
    return cnt;
}

int main(){
    long long int a,b;
    cin>>a>>b;
    long long int t1 = get_zeros(a) - get_zeros(a-b) - get_zeros(b);
    long long int t2 = get_zeros2(a) - get_zeros2(a-b) - get_zeros2(b);
    cout<<min(t1,t2);
}