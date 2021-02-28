#include<iostream>
#include<cstring>
using namespace std;
int main(){
    int wow;
    cin>>wow;
    for(int cs = 0; cs<wow; cs++){
        char str[80];
        cin>>str;
        int score = 0;
        int stk = 0;
        for(int i =0; i<strlen(str); i++){
            if(str[i] == 'O'){
                score += ++stk;
            }else
                stk = 0;
        }
        cout<<score<<endl;
    }
    return 0;
}