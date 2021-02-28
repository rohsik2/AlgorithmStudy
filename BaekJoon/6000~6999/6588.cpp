#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool is_prime[1000001];
vector<int> primes;

int main(){
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);
  for(int i =0 ; i<1000001; i++)
    is_prime[i] = true;
  
  int temp = 4;
  while(temp < 1000001){
        is_prime[temp] = false;
        temp += 2;
  }
  
  for(int i = 3 ; i<1000001; i = i+2){
    if(is_prime[i]){
      int walker = i*2;
      while(walker < 1000001){
        is_prime[walker] = false;
        walker += i;
      }
    }
  }

  for(int i = 2 ; i<1000001; i++)
    if(is_prime[i])
      primes.push_back(i);
  while(true){
    int target;
    cin>>target;
    if(target == 0)
      return 0;
    bool found = false;
    for(auto& p1 : primes){
      int p2 = primes[lower_bound(primes.begin(), primes.end(), target-p1) - primes.begin()];
      if(p1 + p2 == target){
        cout<<target <<" = "<<p1<<" + "<<p2<<'\n';
        break;
      }
    }
  }
}