
// File name: A3_SheetPb1_20220220
// Purpose: Solving Problem 1 ; Assignment 3
// Author(s): OMAR AHMED MOHAMED SALEH    Ahmed Rabie Ahmed Hassanane   
// ID(s): 20220220                        20221007
// Section: 7,8
// Date: 4/12/2023


#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std ;

//******************************************************************
//******************************************************************

class LabelGenerator{

protected :
    string prefix ;
    int counter ;

public :
    LabelGenerator();
    LabelGenerator(string p , int c);
    LabelGenerator& nextLabel();
    friend ostream& operator<<(ostream& os, const LabelGenerator& labelGen);
    
};

//******************************************************************
//******************************************************************

// constructors 

LabelGenerator::LabelGenerator() : prefix("Figure") , counter(1){}

LabelGenerator::LabelGenerator(string p , int c) : 
prefix(p) , counter(c){}

//------------------------------------------------------------------

LabelGenerator& LabelGenerator::nextLabel() {
    counter++ ;
    return *this ;
}

//------------------------------------------------------------------

ostream& operator<<(ostream& os, const LabelGenerator& labelGen) {
    os << labelGen.prefix << ' ' << labelGen.counter ;
    return os;
}

//******************************************************************
//******************************************************************

class FileLabelGenerator : public LabelGenerator {
private:
    string fileName;
    ifstream file ;
    string line ;
public:
    FileLabelGenerator(string p, int c, string f);
    ~FileLabelGenerator();
    FileLabelGenerator& nextLabel() ;
    friend ostream& operator<<(ostream& os, const FileLabelGenerator& labelGen);

};

//******************************************************************
//******************************************************************

FileLabelGenerator::FileLabelGenerator(string p, int c, string f) :
LabelGenerator(p,c) , fileName(f) {
    while (!file.is_open()) {
        file.open(fileName);
        if (!file.is_open()) {
            cerr << "Unable to open the input file\n";
            cerr << "Please enter a valid name or \"exit\" to exit: ";
            cin >> fileName;
            if(fileName=="exit"){break;}   
            cout << '\n';
        }
        getline(file, line);
    }

}

//------------------------------------------------------------------

FileLabelGenerator& FileLabelGenerator::nextLabel(){
    this->counter++;
    if(!getline(file, line)){line="";}
    return *this ;
}

//------------------------------------------------------------------

ostream& operator<<(ostream& os, const FileLabelGenerator& labelGen) {
    os << labelGen.prefix << ' ' << labelGen.counter << ' ' << labelGen.line << '\n';
    return os;
}

//------------------------------------------------------------------

FileLabelGenerator::~FileLabelGenerator(){
    file.close();
}

//------------------------------------------------------------------

int main(){
    LabelGenerator label1;
    cout << "\nDefault Constructor : " << label1 << ' ';
    for(int i=0 ; i<3 ; i++){cout << label1.nextLabel() << ' ' ;}
    cout << '\n';

    LabelGenerator label2("Image", 5);
    cout << "Parameterized Constructor Image with start 5 : " << label2 << ' ';
    for(int i=0 ; i<3 ; i++){cout << label2.nextLabel() << ' ' ;}
    cout << '\n';

    cout << "\nFileLabelGenerator : \n";

    FileLabelGenerator FL("figure",1,"file.txt") ; cout << FL ;
    int n = 5 ;
    while(n--){
        cout << FL.nextLabel()  ;
    }
    
    return 0 ;
}
