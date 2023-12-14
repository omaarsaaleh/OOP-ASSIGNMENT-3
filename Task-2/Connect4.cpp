#include <iostream>
#include"../include/BoardGame_Classes.hpp"
#include "../include/PyramidHeaders.hpp"
#include "../include/Connect4Headers.hpp"
#include"Player.cpp"
#include"RandomPlayer.cpp"
#include"GameManager.cpp"
#include"X_O_Board.cpp"
#include"Connect4_Board.cpp"
using namespace std;

int main() {
    int choice;
    Player* players[2];
    players[0] = new Player (1, 'x');

    cout << "Welcome to FCAI X-O Game. :)\n";
    cout << "Press 1 if you want to play with computer: ";
    cin >> choice;
    if (choice != 1)
        players[1] = new Player (2, 'o');
    else
        //Player pointer points to child
        players[1] = new Connect4RandomPlayer ('o', 7);

    GameManager Connect4Game (new Connect4_Board(), players);
    Connect4Game.run();
    system ("pause");

}
