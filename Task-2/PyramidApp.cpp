// File name: PyramidApp.cpp
// Purpose: Pyramid Game App
// Author(s): Omar Ahmed Mohamed || Ahmed Rabie Ahmed 
// ID(s):     20220220           || 20221007
// Section: 7,8
// Date: 16/12/2023
// Version: 1

#include <iostream>
#include"../include/BoardGame_Classes.hpp"
#include "../include/PyramidHeaders.hpp"
#include "../include/Connect4Headers.hpp"
#include"Player.cpp"
#include"RandomPlayer.cpp"
#include"GameManager.cpp"
#include"X_O_Board.cpp"
#include"Connect4_Board.cpp"
#include"Pyramid.cpp"
using namespace std;

int main() {
    string again = "yes" ;
    while(again == "yes"){
        int choice ;
        Player* players[2];
        Board * board = new PyramidBoard();

        cout << "Welcome to Pyramid Tic Tac Toe Game";
        cout << "\nEnter Player 1 Symbol : ";
        char s1 ; cin >> s1 ;
        cout << "\nEnter Player 2 Symbol : ";
        char s2 ; cin >> s2 ;
        
        cout << "\n\nChoose Player 1 :";
        cout << "\n1 - User\n2 - AI\n3 - Random Computer Player\n";
        cin >> choice ;
        
        switch (choice)
        {
        case 1:
            players[0] = new Player(1,s1);
            break;
        case 2 :
            players[0] = new AIplayer (s1 , s2 , 5, dynamic_cast<PyramidBoard*>(board)) ;
            break;
        case 3 :
            players[0] = new PyramidRandomPlayer(s1 , 5);
            break;
        default:
            break;
        }
        

        cout << "\n\nChoose Player 2 :";
        cout << "\n1 - User\n2 - AI\n3 - Random Computer Player\n";
        cin >> choice ;
        
        
        switch (choice)
        {
        case 1:
            players[1] = new Player(2,s2);
            break;
        case 2 :
            players[1] = new AIplayer (s2 , s1 , 5, dynamic_cast<PyramidBoard*>(board)) ;
            break;
        case 3 :
            players[1] = new PyramidRandomPlayer(s2 , 5);
            break;
        default:
            break;
        }

        GameManager PyramidGame(board,players);
        PyramidGame.run();
        system ("pause");

        cout << "Do you want to play again?\n";
        cout << "answer with yes or no : ";
        cin >> again ;
    }
    return 0 ;

}
