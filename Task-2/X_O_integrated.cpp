#include <bits/stdc++.h>
#include "game_3_20221007_20220220.h"
#include "BoardGame_Classes.hpp"
#include "PyramidHeaders.hpp"
#include "Connect4Headers.hpp"
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

       GameManager x_o(new Connect4_Board(), players);
       x_o.run();
   }
   else {
       cout << "enter 1 to play with computer: ";
       cin >> choice;
       if (choice != 1)
           players[1] = new Player(2, 'o');
       else
           players[1] = new RandomPlayer5('o', 5);

       GameManager x_o(new X_O_5(), players);
       x_o.run();
   }
}