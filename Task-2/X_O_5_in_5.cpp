#include <bits/stdc++.h>
#include "BoardGame_Classes.hpp"
using namespace std ;
int main (){
   int choise ;
   Player* players[2];
   players[0] = new Player(1,'x');
   cout << "welcome\n";
   cout << "enter 1 to play with computer: ";
   cin >> choise;
   if (choise != 1)
       players[1] = new Player(2,'o');
   else
       players[1] = new RandomPlayer5('o',5);
    GameManager5 x_o(new X_O_5(),players);
    x_o.run();
}