#include<iostream>
using namespace std;
int main(){
    while(true){
        int tmp;
        cin>>tmp;
        if(tmp == 0)
            break;
        int len = 1;
        while(tmp>0){
            if(tmp%10 == 0)
                len += 5;
            else if(tmp%10 == 1)
                len += 3;
            else
                len += 4;
            tmp/=10;
        }
        cout<<len<<'\n';
    }
    return 0;
}