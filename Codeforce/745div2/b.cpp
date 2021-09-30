#include <iostream>
#define ll unsigned long long
using namespace std;
 
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    ll n_test_case = 0;
    cin>>n_test_case;
    while(n_test_case --){
        ll n_node, n_edge, k;
        cin>>n_node>>n_edge>>k;
        if (n_node-1 > n_edge){
            cout<<"NO"<<'\n';
            continue;
        }
        else if(n_node * (n_node-1)/2 < n_edge){
            cout<<"NO"<<'\n';
            continue;
        }
        else if (k > 3){
            cout<<"YES"<<'\n';
            continue;
        }
        else if (k == 3){
            if(n_node*(n_node-1)/2 == n_edge){
                cout<<"YES"<<'\n';
                continue;
            }
        }
        else if (k == 2){
            if(n_node == 1 && n_edge ==0){
                cout<<"YES"<<"\n";
                continue;}
        }
        cout<<"NO"<<'\n';
        
    }
    return 0;
}
