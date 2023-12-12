
// File name: A3_SheetPb4_20220220
// Purpose: Solving Problem 4 ; Assignment 3
// Author(s): OMAR AHMED MOHAMED SALEH       Ahmed Rabie Ahmed Hassanane
// ID(s): 20220220                           20221007
// Section: 7,8
// Date: 4/12/2023


#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std ;

template <typename T>
class Set
{
    vector<T> elements;
public:
    Set() {}
    Set(initializer_list<T> initList) {
        for (const auto& element : initList) {
            insert(element);
        }
    }
    ~Set(){ elements.clear(); }
    
    bool searchIfExist(const T& element) const ;
    void insert(const T &element) ;
    void remove(const T &element);
    int size() const;
    T* toDynamicArray() const ;

    typename vector<T>::iterator begin() {
        return elements.begin();
    }

    typename vector<T>::iterator end() {
        return elements.end();
    }
};

//-----------------------------------------------------------

template <typename T>
bool Set<T>::searchIfExist(const T &element) const {
    return binary_search(elements.begin(), elements.end(), element);
}

//-----------------------------------------------------------

template <typename T>
void Set<T>::insert(const T &element) {
    auto it = lower_bound(elements.begin(), elements.end(), element);
    // returns the first element >= 
    if (it == elements.end() || *it != element) {
        elements.insert(it, element);
    }
}

//-----------------------------------------------------------

template <typename T>
void Set<T>::remove(const T &element){
    auto it = std::lower_bound(elements.begin(), elements.end(), element);
    if (it != elements.end() && *it == element) {
        elements.erase(it);
    }
}

//-----------------------------------------------------------

template <typename T>
int Set<T>::size() const{
    return this->elements.size();
}

//-----------------------------------------------------------

template <typename T>
T* Set<T>::toDynamicArray() const {
    T* dynamicArray = new T[elements.size()]; 
    int i = 0;
    for(auto element : elements){
        dynamicArray[i] = element ;
        i++;
    }
    return dynamicArray;
}

//-----------------------------------------------------------


int main(){
    
    Set<int> intSet = {3,1,2,2,5}; // 1 2 3 5
    intSet.insert(4); // 1 2 3 4 5
    intSet.remove(2); // 1 3 4 5
    
    cout << "\nintSet elements : ";
    for (auto element : intSet) {
        cout << element << ' ';
    }

    int* dynamicArray = intSet.toDynamicArray();

    cout << "\ndynamicArray elements : ";
    for (int i = 0; i < 4; ++i) {
        cout << dynamicArray[i] << ' ' ;
    }


    cout << "\nSize = " <<  intSet.size() << '\n' ; // 4

    Set<string> stringSet ; 
    stringSet.insert("banana"); // banana
    stringSet.insert("banana"); // banana
    stringSet.insert("apple"); // apple banana
    stringSet.insert("computer"); // apple banana computer
    
    cout << "\nstringSet elements : " ; 
    for (auto element : stringSet) {
        cout << element << ' ';
    }
    cout <<'\n' ;

    if(stringSet.searchIfExist("banana")){cout << "banana exists\n";}
    if(!stringSet.searchIfExist("orange")){cout << "orange doesn't exist\n";}
    
    
    return 0;


}
