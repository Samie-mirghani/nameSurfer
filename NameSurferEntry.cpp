//Shamsadean Mirghani
//
//Project 2
//
#ifndef NAMESURFERENTRYCPP
#define NAMESURFERENTRYCPP

#include "NameSurferEntry.h"
#include <vector>
#include <algorithm>
#include <sstream>
#include<iostream>
#include<string>
using namespace std;

    NameSurferEntry::NameSurferEntry(string line) {
            
        
            
            char delim = ' ';
            string rank;
            size_t pos=0;
            size_t pos2;
            int count=0;

            pos2 = line.find(delim,pos);
            name = line.substr(0, pos2);
            transform(name.begin(), name.end(), name.begin(), ::tolower);
            pos= pos2+1;
            for(int i=0; i<line.length();i++){
                if(line.at(i) == ' '){
                    count++;
                }
            }
            
            for(int i = 0; i < count + 1; i++) {
                
                pos2 = line.find(delim,pos);
                rank = line.substr(pos, (pos2 - pos));
                
                istringstream buffer(rank);
                int y;
                buffer >> y;
                
                year.push_back(y);
                pos = pos2+1;
            }
    }
    
    NameSurferEntry::NameSurferEntry() {
        name = "none";
        year.clear();
    }
    
    bool NameSurferEntry::empty() {
        if(year.size() == 1) {
            return true;
        }else{
            return false;
        } 
    }
    
    string NameSurferEntry::getName() {
        return name;
    }
    
    int NameSurferEntry::getRank(int decade) {
       
        if(decade == 1910) {
            return year.at(1);
        }
        else if(decade == 1920) {
            return year.at(2);
        }
        else if(decade == 1930) {
            return year.at(3);
        }
        else if(decade == 1940) {
            return year.at(4);
        }
        else if(decade == 1950) {
            return year.at(5);
        }
        else if(decade == 1960) {
            return year.at(6);
        }
        else if(decade == 1970) {
            return year.at(7);
        }
        else if(decade == 1980) {
            return year.at(8);
        }
        else if(decade == 1990) {
            return year.at(9);
        }
        else if(decade == 2000) {
            return year.at(10);
        }
        else if(decade == 2010) {
            return year.at(11);
        }
        else {
            //cout<<"Year 1900\n";
            //if(year.empty()) cout<<"Vector is empty\n";
            return year.at(0);
        }
        
    }
    
    bool NameSurferEntry::operator<(const NameSurferEntry right)const {
        if(this-> name < right.name) {
            return true;
        }
        return false;
    }
    
    bool NameSurferEntry::operator>(const NameSurferEntry right)const {
        if(this-> name > right.name) {
            return true;
        }
        return false;
    } 
    bool NameSurferEntry::operator==(const NameSurferEntry right)const {
        if(this-> name == right.name) {
            return true;
        }
        return false;
    } 
    
    bool NameSurferEntry::operator!=(const NameSurferEntry right)const {
        if(this-> name != right.name) {
            return true;
        }
        return false;
    }  
    
   ostream& operator<<(ostream& out, NameSurferEntry temp) {
       out<<temp.getName();
       return out;
   }
    
    
#endif