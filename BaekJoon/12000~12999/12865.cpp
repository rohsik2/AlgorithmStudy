/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>

#include<algorithm>

using namespace std;
int values[100001][101];
int MAX = 0;

bool MyComparator(pair<int, int> a, pair<int, int> b) {
    if(a.first < b.first){
        return true;
    }
    if(a.first == b.first){
        return a.second > b.second;
    }
    return false;
}

int get_prev_max(int weight, int stuff){
    int large = 0;
    for(int i = 0; i<stuff; i++){
        large = max(large, values[weight][i]);
    }
    return large;
}

int main()
{
    vector<pair<int, int>> stuffs;
    int n_stuff, max_weight;
    cin>>n_stuff >> max_weight;
    int n_stuff2 = n_stuff;
    while(n_stuff2--){
        int a,b;
        cin>>a >> b;
        stuffs.push_back(make_pair(a,b));
    }
    sort(stuffs.begin(), stuffs.end(), MyComparator);
    
    for(int c_weight = 0; c_weight<=max_weight; c_weight++){
        for(int i = 0; i<n_stuff; i++){
            if(c_weight < stuffs[i].first)
                break;
            else{
                values[c_weight][i] = get_prev_max(c_weight-stuffs[i].first, i) + stuffs[i].second;
                if(c_weight>0){
                    values[c_weight][i] = max(values[c_weight][i],values[c_weight-1][i]);
                }
                if (MAX != max(MAX, values[c_weight][i])){
                    MAX = max(MAX, values[c_weight][i]);
//                    cout<<c_weight<<" "<<i <<" "<<values[c_weight][i]<<endl;
                }
                
            }
        }
    }
    /*
    for(auto& arr: values){
        for(auto& temp : arr){
            cout<<temp << " ";
        }
        cout<<endl;
    }
    */
    cout<<MAX;
    return 0;
}
