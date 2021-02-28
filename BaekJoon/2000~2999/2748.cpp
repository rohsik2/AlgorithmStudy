#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    unsigned long long int tm;;
    cin >>tm;
    unsigned long long int l = 0;
    unsigned long long int ll = 1;
    for(int i =1; i<tm; i++){
      unsigned long long int tmp = l+ll;
      l = ll;
      ll = tmp;
    }
    cout<<ll;
}