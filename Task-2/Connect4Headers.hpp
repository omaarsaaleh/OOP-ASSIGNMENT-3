//----------------------------------------------------------------------------
//****************************************************************************
//----------------------------------------------------------------------------
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


#endif