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
    
    cout << "Welcome!\n" ;
    string again = "yes" ;
    
    while(again == "yes"){
        cout << "Select the Game you Want!\n";
        cout << "1 - Pyramid Tic Tac Toe.\n";
        cout << "2 - Connect 4.\n";
        cout << "3 - 5X5 Tic Tac Toe.\n";
        cout << "4 - 3x3 Tic Tac Toe.\n";
        cout << "Enter Your Choice : " ;
        int choice ; cin >> choice ;

        //***********************************************
        // Pyramid
        //***********************************************
        
        if(choice==1){
            int choice2 ;
            Player* players[2];
            Board * board = new PyramidBoard();

            cout << "\nWelcome to Pyramid Tic Tac Toe Game";
            cout << "\nEnter Player 1 Symbol : ";
            char s1 ; cin >> s1 ;
            cout << "\nEnter Player 2 Symbol : ";
            char s2 ; cin >> s2 ;
            
            cout << "\n\nChoose Player 1 :";
            cout << "\n1 - User\n2 - AI\n3 - Random Computer Player\n";
            cin >> choice2 ;
            
            switch (choice2)
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
            cin >> choice2 ;
            
            
            switch (choice2)
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
        }
    
        //***********************************************
        // Connect 4
        //***********************************************
        
    
        else if(choice == 2){
            int choice2 ;
            Player* players[2];
            Board * board = new Connect4_Board();

            cout << "\nWelcome to Connect 4 Game";
            cout << "\nEnter Player 1 Symbol : ";
            char s1 ; cin >> s1 ;
            cout << "\nEnter Player 2 Symbol : ";
            char s2 ; cin >> s2 ;
            
            cout << "\n\nChoose Player 1 :";
            cout << "\n1 - User\n2 - AI\n3 - Random Computer Player\n";
            cin >> choice2 ;
            
            switch (choice2)
            {
            case 1:
                players[0] = new Player(1,s1);
                break;
            case 2 :
                players[0] = new Connect4AIplayer(s1 , s2 , 7, dynamic_cast<Connect4_Board*>(board)) ;
                break;
            case 3 :
                players[0] = new Connect4RandomPlayer(s1 , 7);
                break;
            default:
                break;
            }
            

            cout << "\n\nChoose Player 2 :";
            cout << "\n1 - User\n2 - AI\n3 - Random Computer Player\n";
            cin >> choice2 ;
            
            
            switch (choice2)
            {
            case 1:
                players[1] = new Player(2,s2);
                break;
            case 2 :
                players[1] = new Connect4AIplayer (s2 , s1 , 7, dynamic_cast<Connect4_Board*>(board)) ;
                break;
            case 3 :
                players[1] = new Connect4RandomPlayer(s2 , 7);
                break;
            default:
                break;
            }

            GameManager Connect4Game(board,players);
            Connect4Game.run();
        }
    
        //***********************************************
        // 5x5 Tic Tac Toe
        //***********************************************
    
        else if(choice == 3){
            int choice ;
            Player* players[2];
            Board * board = new X_O_5();
            
            cout << "\nWelcome to 5x5 Tic Tac Game";
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
            
        }

        //***********************************************
        // 3x3 Tic Tac Toe
        //***********************************************

        else if(choice==4){
            
            cout << "\nWelcome to FCAI X-O Game. :)\n";
            cout << "\n\nChoose Player 1 :";
            cout << "\n1 - User\n2 - Random Computer Player\n";
            int choice; cin >> choice ;
            cout << "Choose the Symbol : ";
            char c ; cin >> c ;
            
            Player* players[2];
            
            switch (choice)
            {
            case 1:
                players[0] = new Player(1,c);
                break;
            case 2 :
                players[0] = new RandomPlayer(c,3);
                break;
            default:
                break;
            }

            cout << "\n\nChoose Player 2 :";
            cout << "\n1 - User\n2 - Random Computer Player\n";
            cin >> choice ;
            cout << "Choose the Symbol : ";
            cin >> c ;
            
            switch (choice)
            {
            case 1:
                players[1] = new Player(1,c);
                break;
            case 2 :
                players[1] = new RandomPlayer(c,3);
                break;
            default:
                break;
            }
            GameManager x_o_game (new X_O_Board(), players);
            x_o_game.run();
        }

        system ("pause");
        cout << "Do you want to play again?\n";
        cout << "answer with yes or no : ";
        cin >> again ;
    }
    

    return 0 ;
}