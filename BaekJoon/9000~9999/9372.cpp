#include<iostream>

using namespace std;

int main(){
    int test_case = 0;
    cin>>test_case;
    for(int i = 0; i<test_case; i++){
        int city,air_line;
        int temp1,temp2;
        cin >> city >> air_line;
        for(int j =0; j<air_line; j++){
            cin >> temp1 >> temp2;
        }
        cout<<city-1<<endl;
    }
}