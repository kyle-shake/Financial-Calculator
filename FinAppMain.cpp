/*
File: FinAppMain.cpp
Date: 8/30/17
Last Modified: 12/07/17
Author: Kyle Shake

Purpose: Program will calculate Financial Values for a company based on given values

12/07:
Working on making CashFlows a parent class with children classes (Annuities? Stock Valuation?
etc.) 

11/09:
Still not sure if custom class is necessary. Just working on creating functions for the difference finance
equations. Stopped at Stock Valuation(line 278)

9/27:
Custom class is having difficulties. Maybe just make the map a local variable in main??

9/25:
Make custom class to hold values and names of values!

*/

#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <iterator>
#include <algorithm>
#include <math.h>
#include "CashFlows.h"
#include "BalanceSheet.h"

using namespace std;


// Generic String trimming function to remove whitespace
void trimStr(string& s){
    size_t p = s.find_first_not_of(" \t");
    s.erase(0, p);

    p = s.find_last_not_of(" \t");
    if (string::npos !=p){
        s.erase(p+1);
    }
}

int main(){
    //Initialize all values
    float PV;
    float r;
    float t;



    string menuselection;
    //Numbered menu selection for use on a switch statement below
    CashFlows CurrYearCF;    

    int MenuINT;
    while(MenuINT != 0){

        cout << "Welcome to the Financial Calculator" << endl;
        cout << "Please select from the following menu:" << endl;
        cout << "\t1. Calculate values in Financial Statements and Cash Flows" << endl; 
        cout << "\t2. Calculate Future Value" << endl;
        cout << "\t3. Calculate Annuities or Perpetuities" << endl;
        cout << "\t4. Calculate APR or EAR" << endl;
        cout << "\tType \"0\" to quit" << endl;

        cin >> menuselection;

        trimStr(menuselection);


        try{
            MenuINT = stoi(menuselection);
        }catch(...){
            cout<< "Invalid Menu Selection!" <<endl;
        }

        switch(MenuINT){
            case 1:
                FinStateNCashFlowMenu(CurrYearCF);   
            case 2:
                
            case 3:

            case 4:

            case 0:
                cout << "Thanks for using the Financial Calculator" << endl;
                return 1;

            default:
                cout << "Invalid Menu Option" << endl;
        }
    
    
    }
}





