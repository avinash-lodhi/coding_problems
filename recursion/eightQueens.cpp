#include<iostream>
#include<vector>

using namespace std;

bool place(vector<vector<int>>& chess_board, int r, int c){
    if(r<0 || r>7 || c<0 || c>7){
        return false;
    }
    for(int i =0; i<8;i++){
        if(chess_board[r][i] == 1) return false;
        if(chess_board[i][c] == 1) return false;
        if(r+i<8 && c+i<8 && chess_board[r+i][c+i] == 1) return false;
        if(r-i>=0 && c-i>=0 && chess_board[r-i][c-i] == 1) return false;
    }
    return true;
}

void eightQueens(vector<vector<int>>& chess_board, int r, int &count){
    if(r>7){
        return;
    }
    for(int i=0;i<8;i++){
        bool placement = place(chess_board,r,i);
        if (r==7 && placement){
            count ++;
            return;
        }
        if(placement){
            chess_board[r][i] = 1;
            eightQueens(chess_board,r+1,count);
            chess_board[r][i] = 0;
        }
    }
}

int main(){
    vector<vector<int>> chess_board(8);
    for(int i=0;i<8;i++){
        chess_board[i] = vector<int>(8);
        for(int j=0;j<8;j++){
            chess_board[i][j] = 0;
        }
    }
    int count = 0;
    eightQueens(chess_board,1,count);
    cout << count << endl;
    
}
