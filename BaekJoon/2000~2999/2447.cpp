/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <math.h>
char board[2188][2188];
using namespace std;

void fill_blank(int x, int y, int size){
  for(int i = 0; i<size; i++){
    for(int j = 0; j<size; j++){
      board[x+i][y+j] = ' ';
    }
  }
}

void fill_board(int x, int y, int size){
  if(size == 1)
    return;

  for(int i =0; i<9; i++){
    if(i == 4){
      fill_blank(x + size/3, y + size/3, size/3);
    }
    else 
      fill_board(x + (i/3)*size/3,y + (i%3)*size/3,size/3);
  }
}

int main()
{
    int n;
    cin>>n;
    for(int i = 0; i<2188*2188; i++){
        board[i/2188][i%2188] = '*';
    }
    fill_board(0, 0, n);
    for(int i = 0; i<n; i++){
      for(int j = 0; j<n;j++)
        cout<<board[i][j];
      cout<<"\n";
    }

    return 0;
}
