//Shamsadean Mirghani
//
//Project 2
//
#ifndef NAMESURFERCPP
#define NAMESURFERCPP

#include "NameSurferEntry.h"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


//ostream & operator<<(ostream &out, NamesSurferEntry temp);

    int main() {
        printMenu();
        ifstream inFile;
        
        
        
        return 0;
    }
    
    void printMenu() {
        string input = "1";
        
        while(!(input == "3")) {
            cout << "Menu" << endl;
            cout << "1. Enter a name to be searched" << endl;
            cout << "2. Enter a year" << endl;
            cout << "3. Exit" << endl;
            cout << endl;
            cout << "Choose and option: " << endl;
            cin >> input;
            
            if(input == "1") {
                cout << "Please enter a name: " <<;
                
            }
            else if(input == "2") {
                int year;
                string names;
                vector<string> temp;
                
                cout << "Please Enter a year: " << endl;
                cin >> year;
                
                int compare;
                cout << "Enter how many names you want to compare: ";
                cin >> compare;
                
                for (int i = 0; i < compare; i++) {
                    cout << "Enter Name " << i << ": " << endl;
                    cin >> names
                    temp.insert(names);
                    
                }
                
                
            }
        }
    }
    
    
    //ostream & operator<<(ostream &out, NamesSurferEntry temp) {
        //print histogram here 
        
    }
    