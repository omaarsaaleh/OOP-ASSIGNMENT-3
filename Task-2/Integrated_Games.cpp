// File name: Integrated_Games.cpp
// Purpose: Integrated Games App
// Author(s): Omar Ahmed Mohamed || Ahmed Rabie Ahmed 
// ID(s):     20220220           || 20221007
// Section: 7,8
// Date: 16/12/2023
// Version: 1


#include <iostream>
#include "../include/X_O_5_in_5.hpp"
#include "../include/BoardGame_Classes.hpp"
#include "../include/PyramidHeaders.hpp"
#include "../include/Connect4Headers.hpp"
#include"Player.cpp"
#include"RandomPlayer.cpp"
#include"GameManager.cpp"
#include"X_O_Board.cpp"
#include"Connect4_Board.cpp"
#include"Pyramid.cpp"
#include"TicTacToe5x5.cpp"

using namespace std ;
int main (){
    int choice  ;
    Player* players[2];
    players[0] = new Player(1,'x');
    cout << "welcome\n";
    int choice2;
    cout << "enter 1 to pyramid Tic Tac Toe \n";
    cout << "enter 2 to Four in a row \n";
    cout << "enter 3 to 5X5 Tic Tac Toe \n";
    cout << "enter 4 to Tic Tac Toe \n";
    cin >> choice2;
    if (choice2 == 1) {
        cout << "enter 1 to play with computer: ";
        cin >> choice;
        if (choice != 1)
            players[1] = new Player(2, 'o');
        else
            players[1] = new PyramidRandomPlayer('o', 5);

        GameManager game(new PyramidBoard(), players);
        game.run();
    }
    else if (choice2 == 2){
        cout << "enter 1 to play with computer: ";
        cin >> choice;
        if (choice != 1)
            players[1] = new Player(2, 'o');
        else
            players[1] = new Connect4RandomPlayer('o', 7);

        GameManager game(new Connect4_Board(), players);
        game.run();
    }
    else if(choice2==3){
        cout << "enter 1 to play with computer: ";
        cin >> choice;
        if (choice != 1)
            players[1] = new Player(2, 'o');
        else
            players[1] = new RandomPlayer5('o', 5);

        GameManager game(new X_O_5(), players);
        game.run();
    }
    else{
        cout << "enter 1 to play with computer: ";
        cin >> choice;
        if (choice != 1)
            players[1] = new Player(2, 'o');
        else
            players[1] = new RandomPlayer('o', 3);

        GameManager game(new X_O_Board(), players);
        game.run();    
    }

    return 0 ;
}