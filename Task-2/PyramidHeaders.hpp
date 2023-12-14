//----------------------------------------------------------------------------
//****************************************************************************
//----------------------------------------------------------------------------
// PYRAMID


#ifndef _PyramidBoard_CLASSES_H
#define _PyramidBoard_CLASSES_H
#include "BoardGame_Classes.hpp"

using namespace std;


class PyramidBoard : public Board{
public:
    PyramidBoard();
    bool update_board (int x, int y, char mark);
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


#endif
