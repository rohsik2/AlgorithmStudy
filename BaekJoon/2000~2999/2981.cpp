#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

long long int gcd(long long int a, long long int b){
    if(a == b)
      return a;
    if(a < b){
        long long int tmp = b;
        b = a;
        a = tmp;
    }
    while(b!=0){
        long long int n = a%b;
        a = b;
        b = n;
    }
    return a;
}

int main(){
    long long int n_num;
    cin>>n_num;
    vector<long long int> v;
    long long int small = 223372036854775807;
    long long int temp1;
    cin>>temp1;
        
    while(--n_num){
        long long int temp2;
        cin>>temp2;
        v.push_back(abs(temp1-temp2));
        temp1 = temp2;
    }

    long long int cnt = v[0];
    for(auto& walker : v)
      cnt = gcd(cnt, walker);
    
    vector<long long int> ans;
    for(long long int i = 1; i<=sqrt(cnt); i++){
      if(cnt%i == 0){
        ans.push_back(i);
        if(cnt/i != i)
          ans.push_back(cnt/i);
      }
    }
    sort(ans.begin(), ans.end());
    for(auto& walker : ans){
      if(walker == 1)
        continue;
      cout<<walker<<' ';
    }
    return 0;
}