// Class definition for Connect 4
// Author:  OMAR SALEH
// Date:    11/12/2023
// Version: 1
#include <iostream>
#include <algorithm>
#include <iomanip>
#include "../include/BoardGame_Classes.hpp"
using namespace std;

Connect4_Board::Connect4_Board() {
    // board is a 2D dynamic array to pointers of char 
    n_rows = 6 ; 
    n_cols = 7 ;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
    for(int i=0 ; i<n_cols ; i++){
        first_available[i] = 0 ;
    }
}

//****************************************************************************
// 6 * 7
//****************************************************************************

bool Connect4_Board::update_board (int x, int y, char mark){
    // Only update if move is valid
    if (!(x < 0 || x > 6 || y < 0 || y > 7) && (board[x][y] == 0) && (first_available[y]==5-x) ){
        board[x][y] = toupper(mark);
        n_moves++;
        first_available[y]++;
        return true;
    }
    else
        return false; 
}

void Connect4_Board::display_board() {
    for (int i=0 ; i<6 ; i++) {
        cout << "\n|";
        for (int j=0 ; j<7 ; j++) {
            cout << setw(2) ;
            if(board [i][j]) cout << board [i][j];
            else{cout << ' ';}
            cout <<   " |" ;
        }
        cout << "\n-----------------------------";
    }
   cout << '\n';
}

//****************************************************************************
//****************************************************************************

bool Connect4_Board::is_winner() {
    
    //horizontal
    for(int i=0 ; i<6 ; i++){ // constant row and iterate columns 
        int in_a_row = 1 ;
        for(int j=0 ; j<6 ; j++){ // win casses 0->3, 1->4, 2->5 , 3->6
            if(board[i][j] == board[i][j+1] && board[i][j]){ // if not equal to zero and both are equal
                in_a_row++;
                if(in_a_row==4){return true ;}
            }
            else{ // else start from begin
                in_a_row = 1;
            }
        }
    }

    // vertical
    for(int j=0 ; j<7 ; j++){ // constant column and iterate rows 
        int in_a_row = 1 ;
        for(int i=0 ; i<5 ; i++){ // win casses 0->3, 1->4, 2->5
            if(board[i][j] == board[i+1][j] && board[i][j]){ // if not equal to zero and both are equal
                in_a_row++;
                if(in_a_row==4){return true ;}
            }
            else{ // else start from begin
                in_a_row = 1;
            }
        }
    }

    // diagonals of size 4 
    for (int i = 0; i <= n_rows - 4; ++i) {
        for (int j = 0; j <= n_cols - 4; ++j) {
            // the start of the diagonal
            int in_a_row= 1 ;
            for (int k = 0; k < 3; ++k) { // the elements of the diagonal
                if(board[ i+k ][ j+k ] == board[ i+k+1 ][ j+k+1 ] && board[ i+k ][ j+k ]){
                    in_a_row++;
                    if(in_a_row==4){return true ;}
                }
                else{ // else start from begin
                    in_a_row = 1;
                }
            }
    
        }
    }

    // anti diagonals of size 4
    for (int i = 3; i < n_rows; ++i) {
        for (int j = 0; j <= n_cols - 4; ++j) {
            int in_a_row= 1 ;
            for (int k = 0; k < 3; k++) { // the elements of the diagonal
                if(board[ i-k ][ j+k ] == board[ i-k-1 ][ j+k+1 ] && board[ i-k ][ j+k ]){
                    in_a_row++;
                    if(in_a_row==4){return true;}
                }
                else{ // else start from begin
                    in_a_row = 1;
                }
            }
        }
    }

    return false ;    

}

//****************************************************************************
//****************************************************************************

bool Connect4_Board::is_draw() {
    return (n_moves == 6*7 && !is_winner());
}

bool Connect4_Board::game_is_over () {
    return n_moves >= 6*7;
}



//****************************************************************************
//****************************************************************************


Connect4RandomPlayer::Connect4RandomPlayer (char symbol, int dimension):Player(symbol)
{
    this->dimension = dimension;
    this->name = "Random Computer Player";
    cout << "My names is " << name << endl;
}

// Generate a random move

void Connect4RandomPlayer::get_move( int& x, int& y ) {
    
    y = (int) (rand()/(RAND_MAX + 1.0) * dimension);
    x = (int) (rand()/(RAND_MAX + 1.0) * (dimension-1));
}

//****************************************************************************
//****************************************************************************


