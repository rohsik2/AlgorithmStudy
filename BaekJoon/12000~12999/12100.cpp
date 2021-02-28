#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

vector<vector<int>> board;

int b_size;

int large = -1;

vector<vector<int>> right(vector<vector<int>> board){
    
    for(int j = b_size-1; j>=0; j--){
        queue<int> stk;    
        for(int i = b_size-1; i>0; i--){
            for(int k = i-1; k>=0; k--){
                if(board[i][j] == board[k][j]){
                    large = max(large, board[i][j] *=2);
                    board[k][j] = 0;
                    break;
                }
                if(board[k][j] != 0)
                    break;
            }
            if(board[i][j] != 0)
                stk.push(board[i][j]);
            board[i][j] = 0;
        }
        stk.push(board[0][j]);
        board[0][j] = 0;
        int idx = b_size-1;
        while(!stk.empty()){
            max(large, board[idx--][j] = stk.front());
            stk.pop();
        }
    }
    return board;
}
vector<vector<int>> left(vector<vector<int>> board){
    for(int j = b_size-1; j>=0; j--){
        queue<int> stk;    
        for(int i = 0; i<b_size-1; i++){
            for(int k = i+1; k<b_size; k++)
            {    if(board[k][j] == board[i][j]){
                    large = max(large, board[i][j] *=2);
                    board[k][j] = 0;
                    break;
                }
                if(board[k][j] != 0)
                    break;
            }
            if(board[i][j] != 0)
                stk.push(board[i][j]);
            board[i][j] = 0;
        }
        stk.push(board[b_size-1][j]);
        board[b_size-1][j] = 0;
        int idx = 0;
        while(!stk.empty()){
            max(large, board[idx++][j] = stk.front());
            stk.pop();
        }
    }
    return board;
}
vector<vector<int>> up(vector<vector<int>> board){
    
    for(int j = b_size-1; j>=0; j--){
        queue<int> stk;    
        for(int i = b_size-1; i>0; i--){
            for(int k = i-1; k>=0; k--){
                if(board[j][i] == board[j][k]){
                    large = max(large, board[j][i] *=2);
                    board[j][k] = 0;
                    break;
                }
                if(board[j][k] != 0)
                    break;
            }
            if(board[j][i] != 0)
                stk.push(board[j][i]);
            board[j][i]=0;
        }
        stk.push(board[j][0]);
        board[j][0]=0;
        int idx = b_size-1;
        while(!stk.empty()){
            max(large, board[j][idx--] = stk.front());
            stk.pop();
        }
    }
    return board;
}
vector<vector<int>> down(vector<vector<int>> board){
    for(int j = b_size-1; j>=0; j--){
        queue<int> stk;    
        for(int i = 0; i<b_size-1; i++){
            for(int k = i+1; k<b_size; k++){
                if(board[j][k] == board[j][i]){
                    large = max(large, board[j][i] *=2);
                    board[j][k] = 0;
                    break;
                }
                if(board[j][k] != 0)
                    break;
            }
            if(board[j][i] != 0)
                stk.push(board[j][i]);
            board[j][i]=0;
        }
        stk.push(board[j][b_size-1]);
        board[j][b_size-1]=0;
        int idx = 0;
        while(!stk.empty()){
            max(large, board[j][idx++] = stk.front());
            stk.pop();
        }
    }
    return board;
}

vector<vector<int>> move(int op_code, vector<vector<int>> board){
    switch(op_code){
        case 0 :
            return right(board);
        case 1 :
            return left(board);
        case 2 :
            return up(board);
        default :
            return down(board);
    }
}


const void print(const vector<vector<int>>& temp){
    cout<<endl<<endl;
    for(auto& row : temp){
        for(auto& col : row)
            cout<<col<<' ';
        cout<<endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin>>b_size;
    board.resize(b_size);
    for(int i =0 ;i<b_size*b_size; i++){
        int temp;
        cin>>temp;
        large = max(temp,large);
        board[i/b_size].push_back(temp);
    }
    
    int prev = -1;
    for(int i = 0; i<4*4*4*4*4; i++){
        int ops = i;
        auto temp_board = board;
        for(int j= 0; j<5; j++){
            temp_board = move(ops%4, temp_board);
            prev = ops%4;
            ops /= 4;
        }
    }
    cout<<large;
    return 0;
    
}