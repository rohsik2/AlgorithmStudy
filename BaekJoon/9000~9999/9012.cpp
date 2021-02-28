#include <iostream>
#include<string>
using namespace std;

int main()
{
    int cnt2;
    cin>>cnt2;
    while(cnt2--){
        int cnt = 0;
        int i;
        string temp;
        cin>>temp;
        for(i = 0; i<temp.length(); i++){
            if(temp[i] == '(')
                cnt++;
            else if (cnt == 0){
                break;
            }else
              cnt--;
        }
        if(i == temp.length() && cnt == 0)
            cout<<"YES"<<'\n';
        else
            cout<<"NO"<<'\n';
    }
}