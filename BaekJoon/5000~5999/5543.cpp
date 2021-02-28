#include<iostream>
using namespace std;
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int b1,b2,b3;
    cin>>b1>>b2>>b3;
    int d1,d2;
    cin>>d1>>d2;
    int best_b = b1;
    int best_d = d1;
    if(best_b > b2)
        best_b = b2;
    if(best_b > b3)
        best_b = b3;
    if(best_d > d2)
        best_d = d2;
    cout<<best_b+best_d-50;
    return 0;
}