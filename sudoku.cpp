#include<iostream>
using namespace std;

bool isSafe(int board[9][9], int row , int col , int value){
    for(int i = 0; i< 9;i++){
        if(board[3*(row/3)+ (i/3)][3*(col/3) + (i%3)]== value){
            return false;
        }
        if(board[row][i]== value){
            return false;
        }
        if(board[i][col]== value){
            return false ;
        }
    }
    return true;

}
bool sudoku(int board[9][9]){

    int n = 9;
    for(int row = 0 ; row< n; row++){
        for(int col = 0; col<n; col++){


            if(board[row][col]==0){
                for(int poss_val = 1 ; poss_val<=9; poss_val++){
                    if(isSafe(board , row , col , poss_val)){
                        board[row][col] = poss_val;
                        if(sudoku(board)){
                            return true;
                        }
                        else{
                            // backtracking 
                            board[row][col] = 0;
                        }
                    }
                }
                return false;
            }

        }

    }
    return true;
}

int main(){
    int board[9][9];
    for(int i = 0 ; i<9; i++){
        for(int j = 0 ;j< 9 ;j++){
            cin>>board[i][j];
        }
    }
    cout<<endl;
    sudoku(board);

    for(int i = 0 ; i<9; i++){
        for(int j = 0 ;j< 9 ;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}