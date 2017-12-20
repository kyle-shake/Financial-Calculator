/*
File: BalanceSheet.cpp
Author: Kyle Shake
Date Created: 9/27/17
Last Modified: 9/27/17
Purpose: Provides implentation of functions for the custom BalanceSheet class
*/


#include "BalanceSheet.h"
#include <string>
#include <cmath>
#include <map>
#include <iostream>

using namespace std;

BalanceSheet::BalanceSheet(){
    BSmap["Current Assets"] = 0;
    BSmap["Cash on Hand"] = 0;
    BSmap["Accounts Recievable"] = 0;
    BSmap["Inventory"] = 0;
    BSmap["Fixed Assets"] = 0;
    BSmap["Previous Year Fixed Assets"] = 0;
    BSmap["PP&E"] = 0;
    BSmap["Total Assets"] = 0;
    
    BSmap["Current Liabilities"] = 0;
    BSmap["Accounts Payable"] = 0;
    BSmap["Notes Payable"] = 0;
    BSmap["Long-Term Debt"] = 0;
    
    BSmap["Owners' Equity"] = 0;
    BSmap["Common Stock"] = 0;
    BSmap["Retained Earnings"] = 0;

    BSmap["Total Liabilities and Owners' Equity"] = 0;

    BSmap["Stock Price"] = 0;
    BSmap["Number of Shares"] = 0;
    BSmap["Market Value of Equity"] = 0;
    BSmap["Average Tax Rate"] = 0;
    BSmap["Taxable Income"] = 0;
    BSmap["Taxes Paid"] = 0;
    
    BSmap["Net Sales"] = 0;
    BSmap["Cost of Goods Sold"] = 0;
    BSmap["Depreciation"] = 0;
    BSmap["Earnings Before Interest & Taxes"] = 0;
    BSmap["Interest Paid"] = 0;
    BSmap["Net Income"] = 0;

}

void BalanceSheet::fillBalanceSheet(){

    map<string, int>::iterator it = BSmap.begin();

    while (it != BSmap.end()){
         cout << "Enter the value for " << it->first << " (Enter 0 if not known): ";
         cin >> it->second;
         cout << endl;
         it++;
    }
}

void BalanceSheet::BalanceSheetMenu(){

    
    string menuSelect;
    cout << "\t1. Calculate Net Working Capital" << endl;
    cout << "\t2. Calculate Average Tax Rate" << endl;
    cout << "\t3. Calculate Operating Cash Flow" << endl;
    cout << "\t4. Calculate Net Capital Spending" << endl;
    cout << "\t5. Calculate Market Value of Equity" << endl;
    cout << "\t6. Calculate Cash Flow to Creditors or Shareholders" << endl;

    cin >> menuSelect;
    
    trimStr(menuSelect);  //Change needed here 12/7: KWS

    int MenuINT = 0;
    try{
        MenuINT = stoi(menuSelect);
    } catch(...){
        cout << "Invalid Menu Selection!"<<endl;
    } 

    switch(MenuINT){
        case 1:
            cout << "Calculate Net Working Capital" << endl;
               
            cout << "The current value for Net Working Capital is $" << NWC << endl;
        case 2:
            cout << "Average Tax Rate" << endl;
            
        case 3:
            cout << "Operating Cash Flow" << endl;
            
        case 4:
            cout << "Net Capital Spending" << endl;
            
        case 5:
            cout << "Market Value of Equity" << endl;
            
        case 6:
            cout << "Cash Flows" << endl;
    }
}



void BalanceSheet::currAssetsCalc(){
    BSMap["Current Assets"] = BSmap["Cash on Hand"] + BSmap["Accounts Recievable"] + BSmap["Inventory"];
}

void BalanceSheet::currLiabCalc(){
    BSmap["Current Liabilities"] = BSmap["Accounts Payable"] + BSmap["Notes Payable"];
}

void BalanceSheet::NWCcalc(){
    NWC = BSmap["Current Assets"] - BSmap["Current Liabilities"];
}

//NEED TO CHANGE THE VARIABLES TO REFLECT THE MAP ******** 12/7: KWS
void BalanceSheet::NCScalc(){
    NCS = currNetFixAssets - prevNetFixAssets + deprec;
}

void BalanceSheet::OCFcalc(){
    OCF = EBIT + deprec - taxes;
}

void BalanceSheet::cashFlowToCredcalc(){
    return interestPaid - netNewBorrowing;
}

/*void BalanceSheet::cashFlowtoStockHcalc(float dividends, float netNewEquity){
    return dividends - netNewEquity;
}
DEBUG
*/

void BalanceSheet::netNewEquitycalc(){
    netNewEquity = currStock - prevStock;
}
void BalanceSheet::TaxesOwedcalc(){
    float taxesOwed = 0;
    
    if (taxIncome <= 0){
        cout << "No income to tax!" << endl;
        return taxesOwed;
    }
    if (taxIncome > 18333334){
        taxesOwed += 0.35*(taxIncome - 18333334) + TaxMap[1] + TaxMap [2] + TaxMap[3]
                    + TaxMap[4] + TaxMap[5] + TaxMap[6] + TaxMap[7];
        return taxesOwed;
    }
    if (taxIncome > 15000000){
        taxesOwed += 0.38*(taxIncome - 15000000) + TaxMap[1] + TaxMap [2] + TaxMap[3]
                    + TaxMap[4] + TaxMap[5] + TaxMap[6];
        return taxesOwed;
    }
    if (taxIncome > 10000000){
        taxesOwed += 0.35*(taxIncome - 10000000) + TaxMap[1] + TaxMap [2] + TaxMap[3]
                    + TaxMap[4] + TaxMap[5];
        return taxesOwed;
    }
    if (taxIncome > 335000){
        taxesOwed += 0.34*(taxIncome - 335000) + TaxMap[1] + TaxMap [2] + TaxMap[3]
                    + TaxMap[4];
        return taxesOwed;
    }
    if (taxIncome > 100000){
        taxesOwed += 0.34*(taxIncome - 100000) + TaxMap[1] + TaxMap [2] + TaxMap[3];
        return taxesOwed;
    }
    if (taxIncome > 75000){
        taxesOwed += 0.34*(taxIncome - 75000) + TaxMap[1] + TaxMap [2];
        return taxesOwed;
    }
    if (taxIncome > 50000){
        taxesOwed += 0.25*(taxIncome - 50000) + TaxMap[1];
        return taxesOwed;
    }
    if (taxIncome > 0){
        taxesOwed += 0.15*taxIncome;
        return taxesOwed;
    }
    cout << "Something went wrong!" << endl;
    return 0;

}


