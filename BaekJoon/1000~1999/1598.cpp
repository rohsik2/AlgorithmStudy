#include<iostream>
#include<cstdlib>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    a= a-1;
    b= b-1;
    cout<<abs(a/4 - b/4) + abs(a%4 - b%4);
}