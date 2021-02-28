#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long int arr[101] = {1, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9, 0,};

long long int do_dynamic(int n){
  if(arr[n] != 0){
    return arr[n];
  }
  else{
    long long int result = do_dynamic(n-1) + do_dynamic(n-5);
    arr[n] = result;
    return result;
  }
}

int main(){
  int t,n;
  cin>>t;
  for(int i = 0; i<t; i++){
    cin>>n;
    cout<<do_dynamic(n)<<"\n";
  }
}


