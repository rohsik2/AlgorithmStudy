#include<iostream>
using namespace std;
void swap(int& a, int &b){
    int temp = a;
    a=b;
    b=temp;
}
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int a,b,c;
    cin >>a >>b>>c;
    if(a>b){
        swap(a,b);
    }
    if(b>c){
        swap(b,c);
    } if(a>b){
        swap(a,b);
    }
    cout<<b;
}