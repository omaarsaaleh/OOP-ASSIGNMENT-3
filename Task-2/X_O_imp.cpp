#include "game_3_20221007_20220220.h"
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

if (player_score_x > player_score_o && n_moves == 24)
    cout << "X wins \n";
else if (player_score_o > player_score_x && n_moves == 24)
    cout << "O wins \n";
    return false;
}

bool X_O_5::is_draw() {
    return (player_score_x == player_score_o && game_is_over());
}

bool X_O_5::game_is_over() {
    return n_moves == 24;
}


//--------------------------------------------------------------------------------------------------


void RandomPlayer5::get_move(int &x, int &y) {
     x = (int) (rand() / (RAND_MAX + 1.0) * dimations);
     y = (int) (rand() / (RAND_MAX + 1.0) * dimations);
}

RandomPlayer5::RandomPlayer5(char s, int d) : Player(s) {
         this->dimations = d;
         this->name="Random Computer Player";
         cout << "MY name is " << name << "\n";
}