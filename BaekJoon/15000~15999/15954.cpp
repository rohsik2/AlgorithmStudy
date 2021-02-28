#include<iostream>
#include<vector>
#include<math.h>
#include <iomanip>
using namespace std;

double calc_v(vector<int>& v, int begin, int end){
  double avr = 0;
  double var = 0;
  for(int j = begin; j<end; j++){
    avr+=v[j];
  }
  avr /= (double)(end-begin);
  for(int j = begin; j<end; j++){
    var += abs(v[j]-avr) * abs(v[j]-avr);
  }
  var /= (double)(end-begin);
  var = sqrt(var);
  return var;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n_num,n_k;
    cin>>n_num>>n_k;
    vector<int> v;
    while(n_num--){
      int temp;
      cin>>temp;
      v.push_back(temp);
    }
    int hottest_idx = -1;
    double hottest_value = 987654321;
    for(int i =n_k; i<=v.size(); i++){
      for(int j = n_k; i-j >= 0; j++)
        hottest_value = min(calc_v(v, i-j, i), hottest_value);
    }
    cout<<fixed<<setprecision(10)<<hottest_value;
    return 0;
}