#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> stk;
    int test_case;
    cin>>test_case;
    string command;
    int num;
    for(int i = 0; i<test_case; i++){
        cin>>command;
        if(!command.compare("push")){
            cin>>num;
            stk.push_back(num);
        }
        if(!command.compare("pop")){
            if(stk.size() == 0)
                cout<<"-1"<<"\n";
            else{
                cout<<stk[stk.size()-1]<<"\n";
                stk.pop_back();
            }
        }
        if(!command.compare("size")){
            cout<<stk.size()<<"\n";
        }
        if(!command.compare("empty")){
            if(stk.size() == 0){
                cout << 1 <<"\n";
            }
            else
                cout << 0 <<"\n";
        }
        if(!command.compare("top")){
            if(stk.size() == 0)
                cout<<"-1"<<"\n";
            else{
                cout<<stk[stk.size()-1]<<"\n";
            }
        }
    }
    return 0;
}