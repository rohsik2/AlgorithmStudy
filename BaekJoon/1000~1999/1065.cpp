#include<iostream>
#include<vector>
using namespace std;

int is_hansu(int wow){
    if (wow<100)
        return true;
    vector<int> a;
    while(wow>0){
        a.push_back(wow%10);
        wow/=10;
    }
    for(int i=0; i<a.size()-2; i++){
        if(a[i+1] - a[i] == a[i+2] - a[i+1])
            continue;
        else
            return false;
    }
    return true;
}
int main(){
    int temp;
    cin >> temp;
    int result = 99;
    if(temp < 100)
        result = temp;
    for(int i = 111; i<=temp; i++){
        if(is_hansu(i)){
            result+=1;
        }
    }
    cout<<result;
    
}
