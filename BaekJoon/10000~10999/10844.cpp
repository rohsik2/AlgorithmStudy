/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <math.h>
unsigned long long int table[100][10];
using namespace std;

int main()
{
    int n;
    cin>>n;
    if(n == 1){
      cout<<9;
      return 0;
    }
    table[0][0] = 0;
    for(int i = 1; i<10; i++){
      table[0][i] = 1;
    }
    for(int i = 1; i<n; i++){
      table[i][0] = table[i-1][1];
      for(int j = 1; j<9; j++){
        table[i][j] = (table[i-1][j-1] + table[i-1][j+1]) % 1000000000;
      }
      table[i][9] = table[i-1][8];
    }
    unsigned long long int sum=0;
    for(auto& walker : table[n-1]){
      sum += walker;
      sum %= 1000000000;
    }
    cout<<sum;

    return 0;
}
