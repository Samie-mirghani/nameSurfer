//Shamsadean Mirghani
//
//Project 2
//



#include "NameSurferDataBase.h"
#include "NameSurferEntry.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <ios>
#include <iomanip>
#include <fstream>
using namespace std;


    void printMenu(NameSurferDataBase &run);
    
    int main() {
        NameSurferDataBase run("NamesData.txt");
        printMenu(run);
        return 0;
    }
    
    void printMenu(NameSurferDataBase &run) {
        cout <<"";
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
                string j;
                cout << "Please enter a name: " << endl;
                cin >> j; 
                transform(j.begin(), j.end(), j.begin(), ::tolower);
                
                NameSurferEntry t;
                t = run.findEntry(j);
                if(t.empty()) {
                    cout << "Name not found" << endl;
                }else {
                //cout<< t.getName()<<endl;
                    j[0] = toupper(j[0]);
                    cout << "You selected " << j << endl;
                    int k = 1900;
                    for(int i = 0; i < 13; i++) {
                    
                        int y = t.getRank(k);
                        //cout<<"After Get Rank\n";
                        string star;
                    
                        if(y <= 49) {
                        star = "-";    
                        }
                        else if(y >= 50 && y <= 99) {
                        star = "*-";
                        }
                    else if(y >= 100 && y <= 149) {
                            star = "**-";
                        }
                        else if(y >= 150 && y <= 199) {
                            star = "***-";
                        }
                        else if(y >= 200 && y <= 249) {
                            star = "****-";
                        }
                        else if(y >= 250 && y <= 299) {
                            star = "*****-";
                        }
                        else if(y >= 300 && y <= 349) {
                            star = "******-";
                        }
                        else if(y >= 350 && y <= 399) {
                            star = "*******-";
                        }
                        else if(y >= 400 && y <= 449) {
                            star = "********-";
                        }
                        else if(y >= 450 && y <= 499) {
                            star = "*********-";
                        }
                        else if(y >= 500 && y <= 549) {
                            star = "**********-";
                        }
                        else if(y >= 550 && y <= 599) {
                            star = "***********-";
                        }
                        else if(y >= 600 && y <= 649) {
                            star = "************-";
                        }
                        else if(y >= 650 && y <= 699) {
                            star = "*************-";
                        }
                        else if(y >= 700 && y <= 749) {
                            star = "**************-";
                        }
                        else if(y >= 750 && y <= 799) {
                            star = "***************-";
                        }
                        else if(y >= 800 && y <= 849) {
                            star = "****************-";
                        }
                         else if(y >= 850 && y <= 899) {
                            star = "*****************-";
                        }
                        else if(y >= 900 && y <= 949) {
                        star = "******************-";
                        }
                        else if(y >= 950 && y <= 999) {
                            star = "*******************-";
                        }
                         else {
                            star = "********************-";
                        }
                    
                    
                    
                        if(i == 0) {
                            cout << "1900" << star << y << endl;
                        }
                        else if(i == 1) {
                            cout << "1910" << star << y << endl;
                        }
                        else if(i == 2) {
                            cout << "1920" << star << y << endl;
                        }
                        else if(i == 3) {
                            cout << "1930" << star << y << endl;
                        }
                        else if(i == 4) {
                            cout << "1940" << star << y << endl;
                        }
                        else if(i == 5) {
                            cout << "1950" << star << y << endl;
                        }
                        else if(i == 6) {
                            cout << "1960" << star << y << endl;
                        }
                        else if(i == 7) {
                            cout << "1970" << star << y << endl;
                        }
                        else if(i == 8) {
                        cout << "1980" << star << y << endl;
                        }
                        else if(i == 9) {
                            cout << "1990" << star << y << endl;
                        }
                        else if(i == 10) {
                            cout << "2000" << star << y << endl;
                        }
                        else if(i == 11) {
                            cout << "2010" << star << y << endl;
                        }
                    k = k + 10;
        
                    }
                }
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
                compare = compare + 1;
                for (int i = 1; i < compare; i++) {
                    cout << "Enter Name " << i << ": " << endl;
                    cin >> names;
                    transform (names.begin(), names.end(), names.begin(), ::tolower);
                    
                    temp.push_back(names);
                    
                    
                }
                
                cout << "You selected the decade " << year << endl;
                for(int k = 0; k < temp.size(); k++) {
                    NameSurferEntry q;
                    q = run.findEntry(temp.at(k));
                    
                    if(q.empty()) {
                        cout << "Name not found" << endl;
                        break;
                    }else {
                        int in = ((year - 1900) / 10);
                        int y = q.getRank(year);
                        string star;
                    
                        if(y <= 49) {
                            star = "-";    
                        }
                        else if(y >= 50 && y <= 99) {
                            star = "*-";
                        }
                        else if(y >= 100 && y <= 149) {
                            star = "**-";
                        }
                        else if(y >= 150 && y <= 199) {
                            star = "***-";
                        }
                        else if(y >= 200 && y <= 249) {
                            star = "****-";
                        }
                        else if(y >= 250 && y <= 299) {
                            star = "*****-";
                        }
                        else if(y >= 300 && y <= 349) {
                            star = "******-";
                        }
                        else if(y >= 350 && y <= 399) {
                            star = "*******-";
                        }
                        else if(y >= 400 && y <= 449) {
                            star = "********-";
                        }
                        else if(y >= 450 && y <= 499) {
                            star = "*********-";
                        }
                        else if(y >= 500 && y <= 549) {
                            star = "**********-";
                        }
                        else if(y >= 550 && y <= 599) {
                            star = "***********-";
                        }
                        else if(y >= 600 && y <= 649) {
                            star = "************-";
                        }
                        else if(y >= 650 && y <= 699) {
                            star = "*************-";
                        }
                         else if(y >= 700 && y <= 749) {
                            star = "**************-";
                        }
                        else if(y >= 750 && y <= 799) {
                            star = "***************-";
                        }
                        else if(y >= 800 && y <= 849) {
                            star = "****************-";
                        }
                         else if(y >= 850 && y <= 899) {
                            star = "*****************-";
                        }
                        else if(y >= 900 && y <= 949) {
                            star = "******************-";
                        }
                        else if(y >= 950 && y <= 999) {
                            star = "*******************-";
                        }
                         else {
                            star = "********************-";
                        }
                
                        string q;
                        q = temp.at(k);
                        //cout << q << endl;
                        //for(int l = 0; l < temp.size(); l++) {
                           // q = temp.at(l);
                            q[0] = toupper(q[0]);
                       // }
                    
                        cout << setw(10) << left << q << star << y << endl;
                    
                    
                    }
                }
            }
        }
    }    
                    
                    
                    
                    
                    
                    
                    