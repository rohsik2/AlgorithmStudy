#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int test_case = 0;
    cin>>test_case;
    vector<int> v;
    int temp;
    for(int i = 0; i<test_case; i++){
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    for(int temp : v)
        cout<<temp<<"\n";
    return 0;
}