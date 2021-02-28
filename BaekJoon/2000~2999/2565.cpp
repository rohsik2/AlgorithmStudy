/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
class Data{
  public:
    int strt;
    int end;
};
class less_than_key{
    public:
        inline bool operator() (const Data& d1, const Data& d2){
            if(d1.strt == d2.strt)
                return d1.end < d2.end;
            return d1.strt < d2.strt;
        }
};
class less_than_key_2{
    public:
        inline bool operator() (const Data& d1, const Data& d2){
            return d1.end < d2.end;
        }
};
using namespace std;

int main()
{
    vector<Data> v;
    int n_line;
    
    cin >> n_line;
    while(n_line--){
        int a,b;
        cin>>a>>b;
        Data temp;
        temp.strt = a;
        temp.end = b;
        v.push_back(temp);
    }
    sort(v.begin(),v.end(),less_than_key());
    vector<Data> lcs;
    for(auto& line : v){
        int i;
        for(i = 0; i<lcs.size(); i++){
            if(lcs[i].end < line.end)
                continue;
            else
                break;
        }
        if (lcs.size() == 0){
            lcs.push_back(line);
            continue;
        }
        int idx = i;
        if(idx == lcs.size())
            lcs.push_back(line);
        else
            lcs[idx] = line;
    }
    cout<<v.size() - lcs.size();
    return 0;
}
