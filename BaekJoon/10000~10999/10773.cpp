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

class Meeting{
    public:
        int begin;
        int end;
        int len;
};

class less_than_key
{
    public:
        inline bool operator() (const Meeting& struct1, const Meeting& struct2)
        {
            return (struct1.len > struct2.len);
        }
};

vector<int> table;

int get_p(int* arr, int target){
    int cnt = 0;
    while(arr[target] != -1){
        target = arr[target];
        cnt++;
        if(cnt > 1000){
            cout<<target<<" "<<arr[target]<<endl;
            break;
        }
        
    }
    return target;
}

int main()
{
    int nonsan,n_meeting;
    cin>>n_meeting;
    for(int i = 0; i<n_meeting; i++){
        int a,b,c;
        cin>>a;
        if(a == 0)
            table.pop_back();
        else
            table.push_back(a);
    }
    int acc = 0;
    for(auto& walker : table){
        acc+=walker;
    }
    cout<<acc;
    
    return 0;
}
