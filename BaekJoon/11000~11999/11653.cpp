/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.
*******************************************************************************/
//회의 시간이 가장 짤은거 선택?
//가장 빨리끝나는거 순서대로 선택?

#include<algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> table;



int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int num;
    cin>>num;
    int nanugi = 2;
    while(num > 1){
        while(num % nanugi == 0){
            num /= nanugi;
            cout<<nanugi<<'\n';
        }
        nanugi++;
    }
    
    return 0;
}
