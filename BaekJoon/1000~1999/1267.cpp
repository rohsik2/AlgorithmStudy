#include<iostream>

using namespace std;
int main(){
    int a;
    cin>>a;
    int price2 = 0;
    int price1 = 0;
    int cnt = 0;
    while(a--){
        int tmp;
        cin>>tmp;
        cnt += tmp;
        price1 += ((tmp)/60 + 1) * 15;
        price2 += ((tmp)/30 + 1) * 10;
    }
    if(price1 == price2){
        cout<<"Y M "<<price2;
    }
    else if (price1 > price2){
        cout<<"Y "<<price2;
    }
    else
        cout<<"M "<<price1;
    return 0;
}