// File name: Pyramid.cpp
// Purpose: Class Definition for Pyramid game
// Author(s): Omar Ahmed Mohamed || Ahmed Rabie Ahmed 
// ID(s):     20220220           || 20221007
// Section: 7,8
// Date: 16/12/2023
// Version: 1
#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include "../include/PyramidHeaders.hpp"
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
        //lastmove = make_pair(x,y);
        return true;
    }
    else
        return false; 
}

bool PyramidBoard::undo_move(int i , int j){
    //if(n_moves && board[lastmove.first][lastmove.second]){
    //    board[lastmove.first][lastmove.second] = 0 ;
    //    n_moves--;
    //    return true;
    //}
    //return false ;
    if ( ( (!i && !j) || (i==1 && j >= 0 && j<= 2) || (i==2 && j >= 0 && j <= 4) ) && (board[i][j]) ){
        board[i][j]=0;
        n_moves--;
        return true ;
    }
    return false ;
    
}

void PyramidBoard::display_board() {
    int space, rows;
    int row = 0 , col = 0 ;

    for(int i = 1; i <= 3; ++i) {
        
        for(space = 1; space <= 3-i; ++space) {
            cout <<"    ";
        }
        cout << "|";
        
        int k=0 ;
        while(k != 2*i-1) {
            cout << setw(2) ;
            if(board [row][col]) cout << board [row][col] ;
            else{cout << ' ';}
            cout <<   " |" ;
            k++;
            col++ ;
            
        }
        
        row++ ;
        col = 0 ;
        cout << "\n---------------------\n";
    }
    cout << '\n';   
}

//****************************************************************************
//****************************************************************************

bool PyramidBoard::is_winner() {
    
    //horizontal
    if(board[1][0] && board[1][0]==board[1][1] && board[1][1]==board[1][2]){return true;}
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



int minimax(PyramidBoard *Board, bool isMaxPlayer , char symbol , char opp_symbol) {
    if(Board->is_winner()){
        if(!isMaxPlayer){ //cout << "Max Player wins!\n";
        return 100 ;}
        else{ //cout << "Min Player wins!\n";
        return -100 ;}
    }
    else if(Board->is_draw()) {//cout << "Game is a draw!\n"; 
    return 0 ;}


    if (isMaxPlayer) {
        int bestScore = INT_MIN;
        for (int i = 0; i < 3 ; ++i) {
            for (int j = 0; j < 2*i+1 ; ++j) {
                if (Board->update_board(i,j,symbol)) {
                    //cout << "Max Player Move: (" << i << ", " << j << ")\n";
                    //Board->display_board();
                    bestScore = max(bestScore, minimax(Board, false , symbol , opp_symbol));
                    Board->undo_move(i,j);
                }
            }
        }
        //cout << bestScore << '\n';
        return bestScore;
    } 
    else { 
        int bestScore = INT_MAX;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 2*i+1 ; ++j) {
                if (Board->update_board(i,j,opp_symbol)) {            
                    //std::cout << "Min Player Move: (" << i << ", " << j << ")\n";
                    //Board->display_board();
                    bestScore = min(bestScore, minimax(Board, true , symbol , opp_symbol));
                    Board->undo_move(i,j);
                }
            }
        }
        //cout << bestScore << '\n';
        return bestScore;
    }
}

pair<int,int> GetBestMove(PyramidBoard *Board , char symbol , char opp_symbol) {
    int bestScore = INT_MIN;
    int bestMoveX = -1;
    int bestMoveY = -1;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2*i+1; ++j) {
            if (Board->update_board(i,j,symbol)) {
                //Board->display_board();
                //cout << "Player Move: (" << i << ", " << j << ")\n";
                int moveScore = minimax(Board, false , symbol , opp_symbol);
                Board->undo_move(i,j);
                
                if (moveScore > bestScore) {
                    bestScore = moveScore;
                    bestMoveX = i;
                    bestMoveY = j;
                    //cout << "MOVE : " << i << ' ' << j << '\n';
                }
            }
        }
    }
    //cout << "Best Move: (" << bestMoveX << ", " << bestMoveY << ")\n";
    return make_pair(bestMoveX,bestMoveY);
    
}

//****************************************************************************
//****************************************************************************

AIplayer::AIplayer (char symbol, char oppsymbol, int dimension, PyramidBoard *board ):Player(symbol)
{
    this->dimension = dimension;
    this->board = board ;
    this->opp_symbol = oppsymbol ;
    this->name = "AI Computer Player";
    cout << "My names is " << name << endl;
}

// Generate a random move

void AIplayer::get_move( int& x, int& y ) {
    
    pair<int,int> move = GetBestMove(board , symbol , opp_symbol);
    x = move.first ;
    y = move.second ;
}
