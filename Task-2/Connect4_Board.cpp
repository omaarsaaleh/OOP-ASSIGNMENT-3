// File name: Connect4_Board.cpp
// Purpose: Class Definition for Connect 4 game
// Author(s): Omar Ahmed Mohamed || Ahmed Rabie Ahmed 
// ID(s):     20220220           || 20221007
// Section: 7,8
// Date: 16/12/2023
// Version: 1
#include <iostream>
#include <algorithm>
#include <iomanip>
#include "../include/BoardGame_Classes.hpp"
#include "../include/Connect4Headers.hpp"
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

bool Connect4_Board::undo_move(int i , int j){
    
    if ( !(i < 0 || i > 6 || j < 0 || j > 7)  && (first_available[j]==5-i+1 ) && (board[i][j]) ){
        board[i][j]=0;
        n_moves--;
        first_available[j]--;
        return true ;
    }
    return false ;
    
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




int minimax(Connect4_Board  *Board, bool isMaxPlayer , char symbol , char opp_symbol, int depth) {
    if(Board->is_winner()){
        if(!isMaxPlayer){ //cout << "Max Player wins!\n";
        return 100 ;}
        else{ //cout << "Min Player wins!\n";
        return -100 ;}
    }
    else if(Board->is_draw() || depth == 5) {//cout << "Game is a draw!\n"; 
    return 0 ;}


    if (isMaxPlayer) {
        int bestScore = INT_MIN;
        for (int i = 5; i >=0 ; --i) {
            for (int j = 0; j < 7 ; ++j) {
                if (Board->update_board(i,j,symbol)) {
                    //cout << "Max Player Move: (" << i << ", " << j << ")\n";
                    //Board->display_board();
                    bestScore = max(bestScore, minimax(Board, false , symbol , opp_symbol , depth+1));
                    Board->undo_move(i,j);
                }
            }
        }
        //cout << bestScore << '\n';
        return bestScore;
    } 
    else { 
        int bestScore = INT_MAX;
        for (int i = 5; i >= 0; --i) {
            for (int j = 0; j < 7 ; ++j) {
                if (Board->update_board(i,j,opp_symbol)) {            
                    //cout << "Min Player Move: (" << i << ", " << j << ")\n";
                    //Board->display_board();
                    bestScore = min(bestScore, minimax(Board, true, symbol , opp_symbol ,depth+1));
                    Board->undo_move(i,j);
                }
            }
        }
        //cout << bestScore << '\n';
        return bestScore;
    }
}

pair<int,int> GetBestMove(Connect4_Board  *Board , char symbol , char opp_symbol) {
    int bestScore = INT_MIN;
    int bestMoveX = -1;
    int bestMoveY = -1;

    for (int i = 5; i >= 0; --i) {
        for (int j = 0; j < 7; ++j) {
            if (Board->update_board(i,j,symbol)) {
                //Board->display_board();
                //cout << "Player Move: (" << i << ", " << j << ")\n";
                int moveScore = minimax(Board, false , symbol , opp_symbol, 0);
                Board->undo_move(i,j);
                
                if (moveScore > bestScore) {
                    bestScore = moveScore;
                    bestMoveX = i; 
                    bestMoveY = j;
                }
            }
        }
    }
   // cout << "Best Move: (" << bestMoveX << ", " << bestMoveY << ")\n";
    return make_pair(bestMoveX,bestMoveY);
    
}



//****************************************************************************
//****************************************************************************

Connect4AIplayer::Connect4AIplayer (char symbol, char opp_symbol, int dimension, Connect4_Board *board ):Player(symbol)
{
    this->dimension = dimension;
    this->board = board ;
    this->opp_symbol = opp_symbol ;
    this->name = "AI Computer Player";
    cout << "My names is " << name << endl;
}

// Generate a random move

void Connect4AIplayer::get_move( int& x, int& y ) {
    
    pair<int,int> move = GetBestMove(board ,symbol , opp_symbol);
    x = move.first ;
    y = move.second ;
}