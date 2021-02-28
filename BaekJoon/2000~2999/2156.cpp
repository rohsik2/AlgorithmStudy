/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

int volume[10001] = {0,};
int acc[10001] = {0,};

int MAX = -987654321;

int main()
{
    int target;
    cin>>target;
    for(int i = 0; i<target; i++){
        cin >> volume[i];
    }
    
    acc[0] = volume[0];
    acc[1] = volume[1] + volume[0];
    acc[2] = max(volume[0]+volume[2] , volume[1]+volume[2]);
    if(target < 3){
        cout<<acc[target-1];
        return 0;
    }
    
    
    for(int i = 3; i<=target; i++){
        //1°³½¬°í ¸Ô±â
        acc[i] = max(acc[i-3] + volume[i-1] + volume[i], acc[i-2] + volume[i]);
        //2°³½¬°í ¸Ô±â
        if(i>3)
            acc[i] = max(acc[i],max(acc[i-4] + volume[i-1] + volume[i], acc[i-3] + volume[i]));
        MAX = max(acc[i],MAX);
    }
    cout<<MAX;
    
    return 0;
}
