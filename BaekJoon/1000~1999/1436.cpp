/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

bool is_666(int n){
    while(n > 0){
        if(n%1000 == 666)
            return true;
        n = n/10;
    }
    return false;
    
}

int main()
{
    int n;
    cin >> n;
    int cnt = 0;
    int walker = 666;
    while(cnt != n){
        if(is_666(walker++))
            cnt++;
    }
    cout<<walker-1;
    return 0;
}