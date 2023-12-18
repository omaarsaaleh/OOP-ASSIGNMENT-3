// File name: X_O_5_in_5.cpp
// Purpose: Class definition for TicTacToe5x5 game classes
// Author(s): Omar Ahmed Mohamed || Ahmed Rabie Ahmed 
// ID(s):     20220220           || 20221007
// Section: 7,8
// Date: 16/12/2023
// Version: 1

#include "BoardGame_Classes.hpp"
#ifndef INC_20221007_GAME_3_GAME_3_20221007_20220220_H
#define INC_20221007_GAME_3_GAME_3_20221007_20220220_H

class X_O_5 : public Board{

public:
    
    char s1 = ' ', s2 = ' ';
    int player_score_x , player_score_o;
    
    X_O_5 ();
    bool update_board (int x, int y, char mark);
    bool undo_move(int i, int j);
    void display_board();
    bool is_winner( );
    bool is_draw();
    bool game_is_over();
    pair<string,int> testboard( );

};

class RandomPlayer5 : public Player{
protected:
    int dimations;
public:
    RandomPlayer5(char s ,int d);
    void get_move(int &x , int &y);
};

class AIplayer5x5 : public Player{
    protected:
        int dimension;
        X_O_5 *board;
    public:
        // Take a symbol and pass it to parent
        AIplayer5x5 (char symbol, int dimension, X_O_5 *board);
        // Generate a random move
        void get_move(int& x, int& y);
};
#endif //INC_20221007_GAME_3_GAME_3_20221007_20220220_H
