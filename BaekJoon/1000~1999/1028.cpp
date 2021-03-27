#include <iostream>
#include <string>
using namespace std;

int board1[750][750];
int board2[750][750];
int board3[750][750];

int min3(int a, int b, int c){
    return min(a,min(b,c));
}

int get_board2(int i, int j){
    if (i>=750 || j > 750 || i<0 || j<0)
        return 0;
    if (board1[i][j] != 1)
        return 0;
    if (board2[i][j] != -1)
        return board2[i][j];

    return board2[i][j] = get_board2(i+1, j+1)+1;
}

int get_board3(int i, int j){
    if (i>=750 || j > 750 || i<0 || j<0)
        return 0;
    if (board1[i][j] != 1)
        return 0;
    if (board3[i][j] != -1)
        return board3[i][j];

    return board3[i][j] = get_board3(i+1, j-1)+1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i=0; i<750*750; i++){
        board2[i/750][i%750] = board3[i/750][i%750] = board1[i/750][i%750] = -1;
    }
    int r, c;//row col
    cin>>r>>c;
    for(int i = 0; i<r; i++){
        string temp;
        cin>>temp;
        for(int j = 0; j<c; j++){
            board1[i][j] = temp[j]-'0';
        }
    }
    int large = -1;
    for(int i = 0; i<r; i++){
        for(int j = 0; j<c; j++){
            if (board1[i][j] == 1){
                int max_len = min(get_board2(i,j), get_board3(i,j));

                for(int k = large; k < max_len; k++){
                    int _a = get_board2(i+k, j-k);
                    int _b = get_board3(i+k, j+k);
                    if (_a > k && _b > k){
                        //cout<<i<<" : "<<j<<" : "<<k<<endl;
                        large = max(large, k);
                    }
                }
            }
        }
    }
    /*
    cout<<"---------------------\n\n\n";
    for(int i = 0; i<c; i++){
        for(int j = 0; j<r; j++){
            cout<<get_board2(i,j);
        }
        cout<<endl;
    }
    cout<<"---------------------\n\n\n";
    for(int i = 0; i<c; i++){
        for(int j = 0; j<r; j++){
            cout<<get_board3(i,j);
        }
        cout<<endl;
    }
    cout<<"---------------------\n\n\n";

*/
    cout<<large+1;
    return 0;
}
