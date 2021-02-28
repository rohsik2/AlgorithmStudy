/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int arr[1003][1003];
    string a,b;
    cin>>a>>b;
    int max_num = -987654321;
    for(int i = 0; i<a.length(); i++){
        for(int j = 0; j<b.length(); j++){
            if(a[i] == b[j]){
                arr[i+1][j+1] = arr[i][j]+1;
            }
            else
                arr[i+1][j+1] = max(arr[i+1][j],arr[i][j+1]);
            if(arr[i+1][j+1] > max_num){
                max_num = arr[i+1][j+1];
            }
            
        }
    }
    cout<<max_num;
    return 0;
}
