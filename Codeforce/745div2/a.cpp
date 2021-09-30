#include <iostream>
#define ll long long
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n_test_case = 0;
    cin>>n_test_case;
    while(n_test_case --){
        int temp;
        cin>>temp;
        ll result = 1;
        for(int i = 3; i <= temp*2; i++){
            result *= i;
            result %= 1000000007;
        }
        result %= 1000000007 ;
        cout<<result<<'\n';
    }
    return 0;
}
