/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

int results[1000003] = {0,};

int min(int a, int b, int c){
    return min(min(a,b),c);
}

int main()
{
    int target;
    cin>>target;
    if(target == 1){
        cout<<0;
        return 0;
    }
    if(target<4){
        cout<<1;
        return 0;
    }
    for(int i =0; i<4; i++)
        results[i] = 1;
    for(int i = 4; i<=target; i++){
        if(i%2 == 0 && i%3 == 0){
            results[i] = min(results[i/2], results[i/3], results[i-1]) + 1;
            continue;
        }
        if(i%2 == 0 && i%3 != 0){
            results[i] = min(results[i/2], results[i-1])+1;
            continue;
        }
        if(i%2 != 0 && i%3 == 0){
            results[i] = min(results[i/3], results[i-1])+1;
            continue;
        }
        results[i] = results[i-1]+1;
    }
    cout<<results[target];
    return 0;
}
