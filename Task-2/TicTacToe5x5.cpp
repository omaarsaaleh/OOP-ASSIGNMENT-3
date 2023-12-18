// File name: TicTacToe5x5.cpp
// Purpose: Class Definition for TicTacToe5x5 game
// Author(s): Omar Ahmed Mohamed || Ahmed Rabie Ahmed 
// ID(s):     20220220           || 20221007
// Section: 7,8
// Date: 16/12/2023
// Version: 1


#include <iostream>
#include <algorithm>
#include <iomanip>
#include "../include/X_O_5_in_5.hpp"

// set the board
X_O_5::X_O_5() {
    n_rows = n_cols = 5;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; ++i) {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; ++j) {
            board[i][j] = 0;
        }
    }
}


//here we check if the player move is valid or not
//and put it on the board
 
bool X_O_5::update_board(int x, int y, char mark) {
    if (s1 == ' ')
        s1 = toupper( mark);
    else if(s2 == ' ')
        s2 = toupper (mark);
    
    if (!(x < 0 || x > 4 || y < 0 || y > 4) && (board[x][y] == 0)){
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    return false;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

bool X_O_5::undo_move(int i , int j){
    
    if ( !(i < 0 || i > 4 || j < 0 || j > 4) && (board[i][j]) ){
        board[i][j]=0;
        n_moves--;
        return true ;
    }
    return false ;
    
}


//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void X_O_5::display_board() {
    cout << "\n-----------------------------------------";
        for(int i : {0, 1, 2, 3, 4}){
            cout << "\n|";
            for (int j : {0, 1, 2, 3, 4}) {
                cout << "(" << i << "," << j << ")";
                cout << setw(2) << board[i][j] << "|";
            }
            cout << "\n-----------------------------------------";
        }
    cout << "\n";
}

//--------------------------------------------------------------------------
//--------------------------------------------------------------------------

pair<string,int> X_O_5::testboard( ){
    int score_s1 = 0;
    int score_s2 = 0;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if ((j + 2 <= 4) && (board[i][j] == board[i][j + 1] && board[i][j+1] == board[i][j + 2])) {
                if (board[i][j] == s1)
                    score_s1++;
                else
                    score_s2++;
            }
        }

    }


//--------------------------------------------------------------------------------------------------
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if ((j + 2 <= 4) && (board[j][i] == board[j+1][i] && board[j+1][i] == board[j+2][i]))
            {
                if (board[j][i] == s1)
                    score_s1 ++ ;
                else
                    score_s2 ++ ;
            }
        }

    }

//--------------------------------------------------------------------------------------------------
    int arri[] = {1,2,2,0,1,2 }, arrj[] = {0,1,0,0,1,2};
    int cnt = 0;
    for(int i: arri){
        for(int j : arrj){
            j = arrj[cnt];
            if ((board[i][j] == board[i+1][j+1] && board[i+1][j+1] == board[i+2][j+2])){
                 if ( board[i][j] == s1)
                     score_s1++;
                 else
                     score_s2++;
            }
            if (i != j) {
                if ((board[j][i] == board[j + 1][i + 1] && board[j + 1][i + 1] == board[j + 2][i + 2])) {
                    if (board[j][i] == s1)
                        score_s1++;
                    else
                        score_s2++;
                }
            }
            cnt++;
            break;
        }

    }
    cnt = 0;
    int arr1[] = {1,2,0,1,0,1,2,2,0} , arr2[] = {4,3,3,2,4,3,2,4,2};
    for (int i : arr1) {
        for (int j : arr2) {
               j = arr2[cnt];
                  if (board[i][j] == board[i+1][j-1]  && board[i+1][j-1] == board[i+2][j-2])
                  {
                      if (board[i][j] == s1)
                          score_s1++;
                      else
                          score_s2++;
                  }
            cnt++;
            break;
        }

    }

    //cout << score_s1 << ' ' << score_s2 << '\n' ;
    if(score_s1==score_s2){
        //cout << "draw from test\n";
        //cout << s1 << ' ' << s2 << '\n';
        return make_pair("D",0);
        
    }
    else {
        //cout << "WIN FROM TEST\n";
        //cout << s1 << ' ' << s2 << '\n';
        return make_pair("W",abs(score_s2-score_s1));
    }
    
}





//--------------------------------------------------------------------------
//--------------------------------------------------------------------------


bool X_O_5::is_winner( ) {
    if(n_moves<24){return false ;}
    int player_score_x = 0;
    int player_score_o = 0;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if ((j + 2 <= 4) && (board[i][j] == board[i][j + 1] && board[i][j+1] == board[i][j + 2])) {
                if (board[i][j] == s1)
                    player_score_x++;
                else
                    player_score_o++;
            }
        }

    }


//--------------------------------------------------------------------------------------------------
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if ((j + 2 <= 4) && (board[j][i] == board[j+1][i] && board[j+1][i] == board[j+2][i]))
            {
               if (board[j][i] == s1)
                    player_score_x++;
               else
                    player_score_o++;
            }
        }

    }

//--------------------------------------------------------------------------------------------------
    int arri[] = {1,2,2,0,1,2 }, arrj[] = {0,1,0,0,1,2};
    int cnt = 0;
    for(int i: arri){
        for(int j : arrj){
            j = arrj[cnt];
            if ((board[i][j] == board[i+1][j+1] && board[i+1][j+1] == board[i+2][j+2])){
                 if ( board[i][j] == s1)
                     player_score_x++;
                 else
                     player_score_o++;
            }
            if (i != j) {
                if ((board[j][i] == board[j + 1][i + 1] && board[j + 1][i + 1] == board[j + 2][i + 2])) {
                    if (board[j][i] == s1)
                        player_score_x++;
                    else
                        player_score_o++;
                }
            }
            cnt++;
            break;
        }

    }
    cnt = 0;
    int arr1[] = {1,2,0,1,0,1,2,2,0} , arr2[] = {4,3,3,2,4,3,2,4,2};
    for (int i : arr1) {
        for (int j : arr2) {
               j = arr2[cnt];
                  if (board[i][j] == board[i+1][j-1]  && board[i+1][j-1] == board[i+2][j-2])
                  {
                      if (board[i][j] == s1)
                          player_score_x++;
                      else
                          player_score_o++;
                  }
            cnt++;
            break;
        }

    }

//--------------------------------------------------------------------------------------------------


if (player_score_x > player_score_o ){
    cout << s1 << " Wins!\n"; 
    return true ;
}
else if (player_score_o > player_score_x ){
    cout << s2 << " Wins!\n"; return true ;
}   
return false;
}

//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------

bool X_O_5::is_draw() {
    return (player_score_x == player_score_o && game_is_over());
}

bool X_O_5::game_is_over() {
    return n_moves == 24;
}





//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------


void RandomPlayer5::get_move(int &x, int &y) {
    x = (int) (rand() / (RAND_MAX + 1.0) * dimations);
    y = (int) (rand() / (RAND_MAX + 1.0) * dimations);
}

RandomPlayer5::RandomPlayer5(char s, int d) : Player(s) {
    this->dimations = d;
    this->name="Random Computer Player";
    cout << "MY name is " << name << "\n";
}

//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------



int minimax(X_O_5 *Board, bool isMaxPlayer , int depth) {
    pair<string,int> test = Board->testboard();
    //cout << test.first << ' ' << test.second << '\n';
    if(test.first=="W"){
        if(!isMaxPlayer){ //cout << "Max Player wins!\n";
        return -test.second ;}
        else{ //cout << "Min Player wins!\n";
        return test.second ;}
    }
    else if( test.first=="D" || depth == 30) {//cout << "Game is a draw!\n"; 
    return 0 ;}


    if (isMaxPlayer) {
        int bestScore = INT_MIN;
        for (int i = 0; i <6 ; ++i) {
            for (int j = 0; j < 6 ; ++j) {
                if (Board->update_board(i,j,Board->s2)) {
                    //cout << "Max Player Move: (" << i << ", " << j << ")\n";
                    //Board->display_board();
                    bestScore = max(bestScore, minimax(Board, false , depth+1));
                    Board->undo_move(i,j);
                }
            }
        }
        //cout << bestScore << '\n';
        return bestScore;
    } 
    else { 
        int bestScore = INT_MAX;
        for (int i = 0; i <6 ; ++i) {
            for (int j = 0; j < 6 ; ++j) {
                if (Board->update_board(i,j,Board->s1)) {            
                    //cout << "Min Player Move: (" << i << ", " << j << ")\n";
                    //Board->display_board();
                    bestScore = min(bestScore, minimax(Board, true ,depth+1));
                    Board->undo_move(i,j);
                }
            }
        }
        //cout << bestScore << '\n';
        return bestScore;
    }
}

pair<int,int> GetBestMove(X_O_5  *Board) {
    int bestScore = INT_MIN;
    int bestMoveX = -1;
    int bestMoveY = -1;

    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            if (Board->update_board(i,j,Board->s2)) {
                //Board->display_board();
                //cout << "Player Move: (" << i << ", " << j << ")\n";
                int moveScore = minimax(Board, false , 0);
                Board->undo_move(i,j);
                
                if (moveScore > bestScore) {
                    bestScore = moveScore;
                    bestMoveX = i;
                    bestMoveY = j;
                }
            }
        }
    }
    cout << "Best Move: (" << bestMoveX << ", " << bestMoveY << ")\n";
    return make_pair(bestMoveX,bestMoveY);
    
}


//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------


AIplayer5x5::AIplayer5x5 (char symbol, int dimension, X_O_5 *board ):Player(symbol)
{
    this->dimension = dimension;
    this->board = board ;
    this->name = "AI Computer Player";
    cout << "My names is " << name << endl;
}

// Generate a random move

void AIplayer5x5::get_move( int& x, int& y ) {
    
    pair<int,int> move = GetBestMove(board);
    x = move.first ;
    y = move.second ;
}
