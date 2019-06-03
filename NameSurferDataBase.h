//Shamsadean Mirghani
//
//Project 2
//
#ifndef NAMESURFERDATA
#define NAMESURFERDATA


#include <vector>
#include <iostream>
#include <string>
#include <fstream>

#include "NameSurferEntry.h"
#include "linked_list.h"
using namespace std;

class NameSurferDataBase {
    
    public:
        NameSurferDataBase(string filename);
        void getNameData(string filename);
        NameSurferEntry findEntry(string name);
    private:
        linked_list<NameSurferEntry> database;
};
#endif
