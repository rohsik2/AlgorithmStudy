/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

int main()
{
    int m,n;
    cin >> n >> m;
    char board[70][70];
    for(int i =0; i<n; i++){
        cin >> board[i];
    }
    int results[50][50];
    for(int x = 0; x <= n-8; x++){
        for(int y = 0; y <= m-8; y++){
            char temp = 'W';
            int cnt = 0;
            for(int i = x; i<x+8; i++){
                for(int j = y; j<y+8; j++){
                    if(board[i][j] == temp)
                        cnt++;
                    temp = (temp == 'W' ? 'B' : 'W');
                }
                temp = (temp=='W' ? 'B' : 'W');
            }
            if(64-cnt > cnt)
                results[x][y] = cnt;
            else
                results[x][y] = 64-cnt;
        }
    }
    int min = 987654321;
    for(int x = 0; x<=n-8; x++){
        for(int y = 0; y<=m-8; y++){
            if(results[x][y] < min)
                min = results[x][y];
        }
    }
    cout<<min;
    return 0;
}