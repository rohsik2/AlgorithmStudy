#include<iostream>

using namespace std;

int main(){
    int a, b;
    cin >> a >>b;
    b -= 45;
    if (b<0){
        a= a-1;
        if(a<0)
            a+=24;
        cout<<a<< " "<<b+60;
    }
    else
        cout << a<<" " << b;
    return 0;
}