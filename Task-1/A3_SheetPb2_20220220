
// File name: A3_SheetPb2_20220220
// Purpose: Solving Problem 2 ; Assignment 3
// Author(s): OMAR AHMED MOHAMED SALEH       Ahmed Rabie Ahmed Hassanane
// ID(s): 20220220                           20221007
// Section: 7,8
// Date: 4/12/2023



#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<cmath>
#include <cctype>

using namespace std ;

class StringSet{
private :
    vector<string> words ;
    string cleanWord(const string &word);
public :
    StringSet(){}
    StringSet(string name , char c);
    void AddFromFile(string filname);
    void AddFromstring(string line);
    void clear();
    void insert(string word);
    void remove(string word);
    int size() const ;
    void print();
    StringSet operator+(const StringSet &otherSet) ;
    StringSet operator*(const StringSet &otherSet) ;
    double ComputeSimilarity(const StringSet &otherSet);
    
};

//----------------------------------------------------

StringSet::StringSet(string name , char c){
    switch (c)
    {
    case 'f':
        AddFromFile(name);
        break;
    
    case 's':
        AddFromstring(name);
        break;
    
    default:
        break;
    }

}

//----------------------------------------------------

string StringSet::cleanWord(const string &word) {
    string cleanedWord;
    for (char c : word) {
        if (isalpha(c)) {
            cleanedWord += tolower(c);
        }
    }
    return cleanedWord;
}

//----------------------------------------------------

void StringSet::insert(string word){
    auto it = find(words.begin(), words.end(), word);
    // If the element is not found, add it to the vector
    if (it == words.end()) {
        words.push_back(word);
    }
}

//----------------------------------------------------

void StringSet::AddFromstring(string line){
    
    istringstream LINE(line);
    string word;
    while (LINE >> word) {
        word = cleanWord(word);
        if (!word.empty()) {
            this->insert(word);
        }
    
    }
    
}

//----------------------------------------------------


void StringSet::AddFromFile(string fileName){
    fstream file ;            
    file.open(fileName);

    if (!file.is_open()) {
        cerr << "Unable to open the file " << fileName << '\n';
        return ;
    }
    
    string line ;
    while(getline(file,line)){
        this->AddFromstring(line);
    }

}


//----------------------------------------------------

void StringSet::clear(){
    words.clear();
}

//----------------------------------------------------

void StringSet::remove(string word){
    transform(cbegin(word), cend(word), begin(word), [](const char i){ return tolower(i); }) ;
    auto it = find(words.begin(), words.end(), word);
    if(it != words.end()){
        words.erase(std::remove(words.begin(), words.end(), word), words.end());
    }
}

//----------------------------------------------------

int StringSet::size() const{
    return this->words.size() ;
}

//----------------------------------------------------

void StringSet::print(){
    for(auto word : words){
        cout << word << ' ';
    }
}

//----------------------------------------------------

StringSet StringSet::operator+(const StringSet &otherSet){
    StringSet Union ;
    for(auto word : this->words){
        Union.insert(word) ;
    }
    for(auto word : otherSet.words){
        Union.insert(word) ;
    }
    return Union ;
}

//----------------------------------------------------
// intersection
StringSet StringSet::operator*(const StringSet &otherSet){
    StringSet itrsctn ;
    for(auto word : this->words){
        auto it = find(otherSet.words.begin(), otherSet.words.end(), word);
        if(it != otherSet.words.end()){
            itrsctn.insert(word) ;
        }        
    }
    return itrsctn ;
}

//----------------------------------------------------

double StringSet::ComputeSimilarity(const StringSet &otherSet){
    return ( ((*this)*otherSet).size() ) / (sqrt(this->size()) * sqrt(otherSet.size()) ) ;
}



//----------------------------------------------------
int main(){
    
    StringSet st("file.txt", 'f'); // 'f' add from file
    StringSet st2("Problem three ; Assignment three" , 's') ; // 's' add from a string
    
    cout << '\n' ;
    cout << "SET1 - " ;st.print(); cout << '\n';
    cout << "SET2 - " ;st2.print(); cout << "\n\n";
    
    StringSet st3 = st2*st ; 

    cout << "Intersection * - "; st3.print();
    
    StringSet st4 = st2+st ;
    cout << "\nUnion + - " ; st4.print();

    cout << "\nSimilarity coeff = ";
    cout << st.ComputeSimilarity(st2) << "\n\n";

    st4.clear();
    cout << "Cleared Union - SET : " ; st4.print() ;
    cout << '\n' ;

    return 0 ;
}
