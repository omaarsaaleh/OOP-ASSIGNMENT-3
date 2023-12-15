//
// Created by Ahmed Rabie on 12/15/2023.
//
#include "BoardGame_Classes.hpp"
#ifndef INC_20221007_GAME_3_GAME_3_20221007_20220220_H
#define INC_20221007_GAME_3_GAME_3_20221007_20220220_H
class X_O_5 : public Board{
public:
    int player_score_x , player_score_o;
    X_O_5 ();
    bool update_board (int x, int y, char mark);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();

};

class RandomPlayer5 : public Player{
protected:
    int dimations;
public:
    RandomPlayer5(char s ,int d);
    void get_move(int &x , int &y);
};
#endif //INC_20221007_GAME_3_GAME_3_20221007_20220220_H
