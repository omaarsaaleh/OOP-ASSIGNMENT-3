// Class definition for Connect 4
// Author:  OMAR SALEH
// Date:    11/12/2023
// Version: 1
#include <iostream>
#include <algorithm>
#include <iomanip>
#include "../include/BoardGame_Classes.hpp"
using namespace std;

PyramidBoard::PyramidBoard() {
    // board is a 2D dynamic array to pointers of char 
    n_rows = 3 ; 
    n_cols = 5 ;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }

}

//****************************************************************************
// 3 * 5
//****************************************************************************

bool PyramidBoard::update_board (int x, int y, char mark){
    // Only update if move is valid
    if ( ( (!x && !y) || (x==1 && y >= 0 && y<= 2) || (x==2 && y >= 0 && y <= 4) ) && (board[x][y] == 0) )  {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false; 
}

void PyramidBoard::display_board() {
    int space, rows;
    int row = 0 , col = 0 ;

    for(int i = 1, k = 0; i <= 3; ++i, k = 0) {
        for(space = 1; space <= 3-i; ++space) {
            cout <<"    ";
        }
        cout << "|";
        while(k != 2*i-1) {
            cout << setw(2) ;
            if(board [row][col]) cout << board [row][col] ;
            else{cout << ' ';}
            cout <<   " |" ;
            ++k;
            col++ ;
            
        }
        
        row ++ ;
        col = 0 ;
        cout << "\n---------------------\n";
    }
    cout << '\n';   
}

//****************************************************************************
//****************************************************************************

bool PyramidBoard::is_winner() {
    
    //horizontal
    int in_a_row = 1 ;
    for(int j=0 ; j<4 ; j++){
        if(board[2][j]==board[2][j+1] && board[2][j] ){
            in_a_row++; 
            if(in_a_row==3){return true;}
        }
        else{in_a_row=1;}
    } 

    // vertical
    if(board[0][0] && board[0][0]==board[1][1] && board[0][0]==board[2][2]){ // 0,0 && 1,1 && 2,2
        return true ;
    }

    // diagonals 
    if(board[0][0] && board[0][0]==board[1][0] && board[0][0]==board[2][0]){ // 0,0 && 1,0 && 2,0
        return true ;
    }   
    if(board[0][0] && board[0][0]==board[1][2] && board[0][0]==board[2][4]){ // 0,0 && 1,2 && 2,4
        return true ;
    }   

    return false ;    

}

//****************************************************************************
//****************************************************************************

bool PyramidBoard::is_draw() {
    return (n_moves == 9 && !is_winner());
}

bool PyramidBoard::game_is_over () {
    return n_moves >= 9 ;
}



//****************************************************************************
//****************************************************************************


PyramidRandomPlayer::PyramidRandomPlayer (char symbol, int dimension):Player(symbol)
{
    this->dimension = dimension;
    this->name = "Random Computer Player";
    cout << "My names is " << name << endl;
}

// Generate a random move

void PyramidRandomPlayer::get_move( int& x, int& y ) {
    
    y = (int) (rand()/(RAND_MAX + 1.0) * dimension);
    x = (int) (rand()/(RAND_MAX + 1.0) * (dimension));
}

//****************************************************************************
//****************************************************************************


