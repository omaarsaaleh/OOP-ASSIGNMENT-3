#include "BoardGame_Classes.hpp"
// set the board
X_O_5::X_O_5() {
    n_rows = n_cols = 5;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; ++i) {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; ++j) {
            board[i][j] = 0;
        }
    }
}
/*
 * here we check if the player move is valid or not
 * and put it on the board
 */
bool X_O_5::update_board(int x, int y, char mark) {
     if (!(x < 0 || x > 4 || y < 0 || y > 4) && (board[x][y] == 0)){
         board[x][y] = tolower(mark);
         n_moves++;
         return true;
     }
    return false;
}

void X_O_5::display_board() {
    cout << "\n-----------------------------------------";
      for(int i : {0, 1, 2, 3, 4}){
          cout << "\n|";
          for (int j : {0, 1, 2, 3, 4}) {
              cout << "(" << i << "," << j << ")";
              cout << setw(2) << board[i][j] << "|";
          }
          cout << "\n-----------------------------------------";
      }
      cout << "\n";
}

bool X_O_5::is_winner() {
     player_score_x = 0;
     player_score_o = 0;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if ((j + 2 <= 4) && (board[i][j] == board[i][j + 1] && board[i][j+1] == board[i][j + 2])) {
                if (board[i][j] == 'x')
                    player_score_x++;
                else
                    player_score_o++;
            }
        }

    }


//--------------------------------------------------------------------------------------------------
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if ((j + 2 <= 4) && (board[j][i] == board[j+1][i] && board[j+1][i] == board[j+2][i]))
            {
               if (board[j][i] == 'x')
                    player_score_x++;
               else
                    player_score_o++;
            }
        }

    }

//--------------------------------------------------------------------------------------------------
    int arri[] = {1,2,2,0,1,2 }, arrj[] = {0,1,0,0,1,2};
    int cnt = 0;
    for(int i: arri){
        for(int j : arrj){
            j = arrj[cnt];
            if ((board[i][j] == board[i+1][j+1] && board[i+1][j+1] == board[i+2][j+2])){
                 if ( board[i][j] == 'x')
                     player_score_x++;
                 else
                     player_score_o++;
            }
            if (i != j) {
                if ((board[j][i] == board[j + 1][i + 1] && board[j + 1][i + 1] == board[j + 2][i + 2])) {
                    if (board[j][i] == 'x')
                        player_score_x++;
                    else
                        player_score_o++;
                }
            }
            cnt++;
            break;
        }

    }
    cnt = 0;
    int arr1[] = {1,2,0,1,0,1,2,2,0} , arr2[] = {4,3,3,2,4,3,2,4,2};
    for (int i : arr1) {
        for (int j : arr2) {
               j = arr2[cnt];
                  if (board[i][j] == board[i+1][j-1]  && board[i+1][j-1] == board[i+2][j-2])
                  {
                      if (board[i][j] == 'x')
                          player_score_x++;
                      else
                          player_score_o++;
                  }
            cnt++;
            break;
        }

    }

//--------------------------------------------------------------------------------------------------

return (player_score_x > player_score_o);

}

bool X_O_5::is_draw() {
    return (player_score_x == player_score_o);
}

bool X_O_5::game_is_over() {
    return n_moves == 24;
}


//--------------------------------------------------------------------------------------------------

// Give player a symbol to use in playing
// It can be X or O or others
// This is needed for computer players
// as it does not ask for a name
Player::Player(char symbol) {
    this->symbol = symbol;
}

// Optionally, you can give him ID or order
// Like Player 1 and Player 2
Player::Player (int order, char symbol) {
    cout << "Welcome player " << order << endl;
    cout << "Please enter your name: ";
    cin >> name;
    this->symbol = symbol;
}

// Get desired move: x y (each between 0 and 2)
// Virtual (can change for other player types)
void Player::get_move (int& x, int& y) {
    cout << "\nPlease enter your move x and y (0 to 4) separated by spaces: ";
    cin >> x >> y;
}

// Give player info as a string
string Player::to_string(){
    return "Player: " + name ;
}

// Get symbol used by player
char Player::get_symbol() {
    return symbol;
}

void RandomPlayer5::get_move(int &x, int &y) {
     x = (int) (rand() / (RAND_MAX + 1.0) * dimations);
     y = (int) (rand() / (RAND_MAX + 1.0) * dimations);
}

RandomPlayer5::RandomPlayer5(char s, int d) : Player(s) {
         this->dimations = d;
         this->name="Random Computer Player";
         cout << "MY name is " << name << "\n";
}


GameManager5::GameManager5(Board *ptr, Player **playerptr) {
    boardPtr = ptr;
    players[0] = playerptr[0];
    players[1] = playerptr[1];

}

void GameManager5::run() {
   int x , y;

   boardPtr->display_board();

   while(!boardPtr->game_is_over()){
       for(int i: {0,1}){
           players[i]->get_move(x,y);
           while (!boardPtr->update_board(x,y,players[i]->get_symbol()))
               players[i]->get_move(x,y);
           boardPtr->display_board();
       }
   }
    if (boardPtr->is_winner())
         cout << players[0]->to_string() << " is the winner!\n";
    else if (boardPtr->is_draw())
        cout << "Draw!\n";
    else
         cout << players[1]->to_string() << " is the winner\n";

}

GameManager5::~GameManager5() {
    delete [] boardPtr ;
}
