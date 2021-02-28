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
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int m,n;
    cin>>n>>m;
    vector<int> v[1000];
    vector<pair<int,int>> b_spread;
    int to_fill = 0;
    for(int i = 0; i<m; i++){
        for(int j =0; j<n; j++){
            int temp;
            cin>>temp;
            v[i].push_back(temp);
            if(temp == 1)
                b_spread.push_back({i,j});
            if(temp == 0)
                to_fill++;
        }
    }
    int cnt =0;
    vector<pair<int,int>> next_spread;
    while(true){
        if(to_fill == 0){
            cout<<cnt;
            return 0;
        }
        if(b_spread.empty()){
            cout<<-1;
            return 0;
        }
        
        cnt ++;
        for(auto& walker : b_spread){
            int i = walker.first;
            int j = walker.second;
            if(i>0 && v[i-1][j] == 0){
                v[i-1][j] = 1;
                next_spread.push_back({i-1,j});
                to_fill--;
            }
            if(i<m-1 && v[i+1][j] == 0){
                v[i+1][j] = 1; 
                next_spread.push_back({i+1,j});
                to_fill--;
            }
            if(j>0 && v[i][j-1] == 0){
                v[i][j-1] = 1; 
                next_spread.push_back({i,j-1});
                to_fill--;
            }
            if(j<n-1 && v[i][j+1] == 0){
                v[i][j+1] = 1; 
                next_spread.push_back({i,j+1});
                to_fill--;
            }
        }
        b_spread = next_spread;
        next_spread.clear();
    }
    
    cout<<cnt;
    
    return 0;
}
