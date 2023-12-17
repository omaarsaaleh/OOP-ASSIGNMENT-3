// File name: PyramidHeaders.cpp
// Purpose: Class definition for Pyramid game classes
// Author(s): Omar Ahmed Mohamed || Ahmed Rabie Ahmed 
// ID(s):     20220220           || 20221007
// Section: 7,8
// Date: 16/12/2023
// Version: 1


// PYRAMID

#include "BoardGame_Classes.hpp"
#ifndef _PyramidBoard_CLASSES_H
#define _PyramidBoard_CLASSES_H


using namespace std;


class PyramidBoard : public Board{
protected :
    //vector <pair<int,int> > lastmove ;
public:
    PyramidBoard();
    bool update_board (int x, int y, char mark);
    bool undo_move(int i, int j);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();

};

class PyramidRandomPlayer: public Player {
    protected:
        int dimension;
    public:
        // Take a symbol and pass it to parent
        PyramidRandomPlayer (char symbol, int dimension);
        // Generate a random move
        void get_move(int& x, int& y);
};

class AIplayer : public Player{
    protected:
        int dimension;
        PyramidBoard *board;
        char opp_symbol ;
    public:
        // Take a symbol and pass it to parent
        AIplayer (char symbol, char oppsymbol, int dimension, PyramidBoard *board);
        // Generate a random move
        void get_move(int& x, int& y);
};



#endif