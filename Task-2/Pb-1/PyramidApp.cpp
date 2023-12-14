#include <iostream>
#include"../include/BoardGame_Classes.hpp"
#include"Player.cpp"
#include"RandomPlayer.cpp"
#include"GameManager.cpp"
#include"X_O_Board.cpp"
#include"Connect4_Board.cpp"
#include"Pyramid.cpp"
using namespace std;

int main() {
    int choice;
    Player* players[2];
    players[0] = new Player (1, 'x');

    cout << "Welcome to FCAI X-O Game. :)\n";
    cout << "Press 1 if you want to play with computer: ";
    cin >> choice;
    if (choice != 1)
        players[1] = new Player (5, 'o');
    else
        //Player pointer points to child
        players[1] = new PyramidRandomPlayer ('o', 5) ;

    GameManager Connect4Game (new PyramidBoard(), players);
    Connect4Game.run();
    
    system ("pause");

}
