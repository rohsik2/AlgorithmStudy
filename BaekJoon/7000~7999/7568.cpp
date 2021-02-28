/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int case_num;
    cin >> case_num;
    int* height = new int [case_num];
    int* weight = new int [case_num];
    int* rank = new int [case_num];

    for(int i =0; i<case_num ; i++){
        cin >> weight[i] >> height[i];
    }
    
    for(int i =0; i<case_num; i++){
        int cnt = 0;
        for(int j =0;j<case_num; j++ ){
            if(weight[i] < weight[j] && height[i] < height[j])
                cnt++;
        }
        rank[i] = cnt+1;
    }
    
    for(int i =0; i<case_num; i++){
        cout<<rank[i]<<" ";
    }
    return 0;
}