//Shamsadean Mirghani
//
//Project 2
//
#ifndef NAMESURFERENTRY_1
#define NAMESURFERENTRY_1

#include <vector>
#include<iostream>
#include<string>
using namespace std;

class NameSurferEntry {
    public:
    
    NameSurferEntry(string line);
    NameSurferEntry();
    string getName();
    int getRank(int decade);
    bool empty();
    bool operator<(const NameSurferEntry right)const;
    bool operator>(const NameSurferEntry right)const;
    bool operator==(const NameSurferEntry right)const;
    bool operator!=(const NameSurferEntry right)const;
    friend ostream& operator<<(ostream& out, NameSurferEntry temp);
    
    private:
    
    string name;
    vector<int> year;
};

#endif
    