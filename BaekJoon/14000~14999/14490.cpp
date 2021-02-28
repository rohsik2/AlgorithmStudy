#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> primes;

bool is_prime(int target){
  for(auto& walker : primes){
    if(target % walker == 0)
      return false;
    if(target < walker*walker)
      return true;
  }
  return true;
}

void set_primes(){
  primes.push_back(2);
  for(int i = 3 ; i<10000; i+=2){
    if(is_prime(i)){
      primes.push_back(i);
    }
  }
}

int main() {
  set_primes();
  string input;
  cin>>input;
  //1억은 int안에 들어갑니다.
  int a = stoi(input.substr(0,input.find(':')));
  int b = stoi(input.substr(input.find(':')+1, input.size()));
  
  for(auto& prime : primes){
    while(prime <= a && a%prime == 0 && b%prime == 0) {
      a/=prime;
      b/=prime;
    }
  }
  cout<<a<<":"<<b;
}