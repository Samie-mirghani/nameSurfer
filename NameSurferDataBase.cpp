    //Shamsadean Mirghani
//
//Project 2
//

#ifndef NAMESURFERDATACPP
#define NAMESURFERDATACPP


#include <algorithm> 
#include <vector>
#include <sstream>
#include <fstream>
#include <unistd.h>
#include<iostream>
#include<string>

#include "NameSurferDataBase.h"
using namespace std;

NameSurferDataBase::NameSurferDataBase(string filename) {
     
     ifstream inFile;
     inFile.open(filename);
     
     string line;
     string name;
     string str;
     string str1;
     string str2;
     string str3;
     string str4;
     string str5;
     string str6;
     string str7;
     string str8;
     string str9;
     string str10;
     stringstream tt;
     
     while(inFile >> name >> str >> str1 >> str2 >> str3 >> str4 >> str5 >> str6 >> str7 >> str8 >> str9 >> str10) {
         line = name + " " + str + " " + str1 + " " + str2 + " " + str3 + " " + str4 + " " + str5 + " " + str6 + " " + str7 + " " + str8 + " " + str9 + " " + str10; 
         //cout << line << endl;
         transform(name.begin(), name.end(), name.begin(), ::tolower);
         NameSurferEntry x(line);
         //cout<<line<<endl;
         database.InsertInOrder(x);
     }
       // database.PrintAll();
     
}


NameSurferEntry NameSurferDataBase::findEntry(string name) {
    NameSurferEntry temp(name); 
    if(database.Search(temp)){
        return temp;
    }else{
        return temp;
    }
}

#endif

    
    
    
    
    
    