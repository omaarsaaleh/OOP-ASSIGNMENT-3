// File name: TicTacToe5x5App.cpp
// Purpose: TicTacToe5x5 game App
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
    
    string again = "yes" ;
    while(again == "yes"){
        int choice ;
        Player* players[2];
        Board * board = new X_O_5();
        
        cout << "Welcome to 5x5 Tic Tac Game";
        cout << "\n\nChoose Player 1 :";
        cout << "\n1 - User\n2 - AI\n3 - Random Computer Player\n";
        cin >> choice ;
        cout << "Choose the Symbol : ";
        char c ; cin >> c ;
        
        switch (choice)
        {
        case 1:
            players[0] = new Player(1,c);
            break;
        case 2 :
            players[0] = new AIplayer5x5(c,5 , dynamic_cast<X_O_5*>(board));
            break;
        case 3 :
            players[0] = new RandomPlayer5(c , 5);
            break;
        default:
            break;
        }


        cout << "\n\nChoose Player 2 :";
        cout << "\n1 - User\n2 - AI\n3 - Random Computer Player\n";
        cin >> choice ;
        cout << "Choose the Symbol : ";
        cin >> c ;
        
        switch (choice)
        {
        case 1:
            players[1] = new Player(2,c);
            break;
        case 2 :
            players[1] = new AIplayer5x5(c,5 , dynamic_cast<X_O_5*>(board));
            break;
        case 3 :
            players[1] = new RandomPlayer5(c , 5);
            break;
        default:
            break;
        }
        
        GameManager x_o(board,players);
        x_o.run();
        system ("pause");
    
        cout << "Do you want to play again?\n";
        cout << "answer with yes or no : ";
        cin >> again ;
    }
    
    return 0 ;
}