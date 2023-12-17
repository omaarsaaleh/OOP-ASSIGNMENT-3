// File name: Connect4Headers.cpp
// Purpose: Class definition for Connect four game Classes
// Author(s): Omar Ahmed Mohamed || Ahmed Rabie Ahmed 
// ID(s):     20220220           || 20221007
// Section: 7,8
// Date: 16/12/2023
// Version: 1



// Connect Four

#ifndef _Connect4Board_CLASSES_H
#define _Connect4Board_CLASSES_H
#include "BoardGame_Classes.hpp"

using namespace std;


class Connect4_Board : public Board{
private:
    int first_available[7];

public:
    Connect4_Board();
    bool update_board (int x, int y, char mark);
    bool undo_move(int i, int j);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();


};

//----------------------------------------------------------------------------

class Connect4RandomPlayer: public Player {
    protected:
        int dimension;
    public:
        // Take a symbol and pass it to parent
        Connect4RandomPlayer (char symbol, int dimension);
        // Generate a random move
        void get_move(int& x, int& y);
};

//----------------------------------------------------------------------------

class Connect4AIplayer : public Player{
    protected:
        int dimension;
        Connect4_Board *board;
        char opp_symbol ;
    public:
        // Take a symbol and pass it to parent
        Connect4AIplayer (char symbol, char opp_symbol , int dimension, Connect4_Board *board);
        // Generate a random move
        void get_move(int& x, int& y);
};

#endif