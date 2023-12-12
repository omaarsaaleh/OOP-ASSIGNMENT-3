/*
 * file name : A3_SheetPb3_20221007
 * purpose: Solve Pb6
 *    name : Ahmed Rabie Ahmed ,Omar Ahmed Mohamed Saleh
 * ID: 20221007, 20220220
 * Section : S7,S8
 * Date : 8/12/2023
*/

#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
class Universe {
private:
    int alive = 0;
    array<array<int , 50 >, 20 > arr;
    void count_neighbors(int x , int y);
    void next_generation( );
    bool isalive(int , int);
public:
    void clearConsole();
    void initialize();
    void reset();
    void run();
    void display();
};
void Universe::count_neighbors(int x , int y) {
    alive = 0;
    // left
    if (x > 0 && arr[x - 1][y] == 1) alive++;
    // right
    if (x < 20 && arr[x + 1][y] == 1) alive++;
    // top
    if (y > 0 && arr[x][y - 1] == 1) alive++;
    // bottom
    if (y < 50 && arr[x][y + 1] == 1) alive++;
    // top left
    if (x > 0 && y > 0 && arr[x - 1][y - 1] == 1) alive++;
    // top right
    if (x < 20 && y > 0 && arr[x + 1][y - 1] == 1) alive++;
    // bottom left
    if (y < 50 && x > 0 && arr[x - 1][y + 1] == 1) alive++;
    // bottom right
    if (x < 50 && y < 20 && arr[x + 1][y + 1] == 1) alive++;
}

void Universe::next_generation( ) {

    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 50; ++j) {
            arr[i][j] = (isalive(i, j)) ? 1 : 0;
        }
    }
}

void Universe::initialize() {
 //   int x , y;
//    int number_of_cells;
//    cout << "enter the number of cells that you want to initialize :\n";
//
//    cin >> number_of_cells;
//    int cnt = 0;
//    while(number_of_cells--) {
//        cnt++;
//        cout << "enter the cells in x y number " << cnt << ":\n" ;
//        cin >> x >> y;
//        arr[x][y] = 1;
//    }
    arr[1][1] = 1;
    arr[1][2] = 1;
    arr[2][1] = 1;
    arr[2][1] = 1;
    arr[3][1] = 1;
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 50; ++j) {
            (arr[i][j]) ? cout << "#" : cout << ".";
        }
        cout << "\n";
    }
}


void Universe::reset() {
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 50; ++j) {
            arr[i][j] = 0 ;
        }
    }

}

void Universe::display() {
    run();
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 50; ++j) {
            (arr[i][j]) ? cout << "#" : cout << ".";
        }
        cout << "\n";
    }

}

bool Universe::isalive(int x , int y) {
    count_neighbors(x, y);
    if (arr[x][y] == 1 && alive < 2) return false;
    if (arr[x][y] == 1 && alive == 2 || alive ==  3) return true;
    if (arr[x][y] == 1 && alive > 3) return false;
    if (arr[x][y] == 0 && alive == 3) return true;
    return false;
}

void Universe::run() {
    next_generation();
}

void Universe::clearConsole() {

    // For Windows
    system("cls");

}
int main() {
    // this code must run in the terminal
    Universe u;
    u.reset();
    int runs = 100 ;
    //cout << "enter the number of rounds: ";
    //cin >> runs ;
    u.initialize();
    Sleep(1000);
    u.clearConsole();
    while(runs--) {
        u.display();
        Sleep(1000);
        u.clearConsole();
    }

    return 0;
}
