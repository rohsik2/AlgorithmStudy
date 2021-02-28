#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

vector<int> getPi(vector<int> & p){ 
    int m = (int)p.size(), j=0;
    vector<int> pi(m, 0);
    for(int i = 1; i< m ; i++){
        while(j > 0 && p[i] != p[j])
            j = pi[j-1];
        if(p[i] == p[j]) 
            pi[i] = ++j;
    } 
    return pi;
}
vector<int> kmp(vector<int>& s, vector<int>& p){ vector<int> ans; auto pi = getPi(p); int n = (int)s.size(), m = (int)p.size(), j =0; for(int i = 0 ; i < n ; i++){ while(j>0 && s[i] != p[j]) j = pi[j-1]; if(s[i] == p[j]){ if(j==m-1){ ans.push_back(i-m+1); j = pi[j]; }else{ j++; } } } return ans; }



int main() {
    int n_data;
    cin>>n_data;
    vector<int> v1;
    vector<int> v2;
    for(int i =0 ; i<n_data; i++){
        int temp;
        cin>>temp;
        v1.push_back(temp);
    }

    for(int i =0 ; i<n_data; i++){
        int temp;
        cin>>temp;
        v2.push_back(temp);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    int prev = 0;
    vector<int> v3;
    for(auto& walker : v1){
        v3.push_back(walker - prev);
        prev = walker;
    }
    v3[0] += 360000-*(v1.end()-1);
    
    prev = 0;
    vector<int> v4;
    for(auto& walker : v2){
        v4.push_back(walker - prev);
        prev = walker;
    }
    v4[0] += 360000- *(v2.end()-1);
    
    for(int i =0 ; i<v1.size(); i++){
        v4.push_back(v4[i]);
    }

    vector<int> result = kmp(v4,v3);
    if(result.size() == 0)
        cout<<"impossible";
    else
        cout<<"possible";
    return 0;
}