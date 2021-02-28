#include <iostream>

using namespace std;

bool is_zegob[1000002];

int main() {
    for(int i =0 ;i<1000002; i++)
        is_zegob[i] = false;
    long long a, b;
    cin>>a>>b;
    for(long long i = 2; i*i<= b; i++){
        long long j = a;
        if((a%(i*i)) != 0){
            j -= a%(i*i);
            j+=i*i;
        } 
        for( ; j <= b; j += i*i)
            is_zegob[j-a] = true;
    }
    long long cnt = 0;
    for(long long i = 0 ; i<=b-a; i++)
        if(!is_zegob[i])
            cnt++;
    cout<<cnt;
    return 0;
}
