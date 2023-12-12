/*
 * file name : A3_SheetPb3_20221007
 * purpose: Solve Pb3
 * name : Ahmed Rabie Ahmed ,Omar Ahmed Mohamed Saleh
 * ID: 20221007, 20220220
 * Section : S7,S8
 * Date : 8/12/2023
 *
*/
#include <bits/stdc++.h>
using namespace std;
class STL_Map {
private:
    string file_name;
    map<string,int> table;
public:
    void set_file(string);
    void print_table();
};

void STL_Map::set_file(string f) { // test.txt
    string t = f.substr(f.size()-4,f.size());
    if (t != ".txt")
        f = f + ".txt";
    file_name = f ;
}
void STL_Map::print_table() {
    fstream my_file;
    my_file.open(file_name, ios::in);
    if (my_file.is_open()){
        string line ;
        while(getline(my_file,line)){
            string word ;
            for (int i = 0; i < line.size() ; ++i) {
                if (ispunct(line[i]) && line[i] != '-')
                {
                    i++;
                    continue;
                }

                if (isalpha(line[i]) || line[i] == '-')
                {
                    word += (line[i] == '-') ? '-' : tolower(line[i]);
                }

                else
                {
                    table[word]++;
                    word.clear();
                }

            }
        }
        cout  << setw(13) << "The word"  << " " << setw(30) << "The number of appearance \n";
        for(auto i : table){
            cout << setw(13) << i.first << setw(13) << i.second << "\n";
        }
    }
    else
    {
        cout << "There is an error in the file name!\n";
    }

}
int main() {
    STL_Map s;
    cout << "Enter the file Name: ";
    string file ;
    cin >> file;
    s.set_file(file);
    s.print_table();
    return 0;
}
