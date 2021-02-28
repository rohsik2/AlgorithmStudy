#include<iostream>
using namespace std;
int main(){
    int a;
    cin >> a;
    if(a/10 >= 9)
        cout<<"A";
    else if (a/10 >7){
        cout<<"B";
    }
    else if (a/10 >6){
        cout<<"C";
    }
    else if (a/10 >5){
        cout<<"D";
    }
    else
        cout<<"F";
    return 0;
}