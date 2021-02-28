#include<iostream>

using namespace std;

int main(){
    int A,B,C;
    cin>>A>>B>>C;
    cout<<(A+B)%C<<endl<<((A%C) + (B%C))%C<<endl;
    cout<<(A*B)%C<<endl<<((A%C) * (B%C))%C;
    return 0;
}