/*
File: BalanceSheet.h
Author: Kyle Shake
Created: 9/27/17
Last Modified: 9/27/17
Purpose: Provides the definition for the custom BalanceSheet class

*/



#ifndef BALANCESHEET_H
#define BALANCESHEET_H

#include <string>
#include <map>

using namespace std;

class BalanceSheet
{
    public:
    //Default Constructor for BalanceSheet class
    BalanceSheet();
    void fillBalanceSheet();
    void BalanceSheetMenu();
    void currAssetsCalc();
    void NWCcalc();
    void NCScalc();
    void OCFcalc();
    void cashFlowToCredcalc();
    void cashFlowToStockHcalc();
    void netNewEquitycalc();
    void TaxesOwedcalc();
    void printBalanceSheetvalues();

    protected:
    float NWC; //Net Working Capital
    float NCS; //Net Capital Spending
    float OCF; //Operating Cash Flow
    float taxesOwed; 
    float netNewEquity;
    map <string, float> BSmap; //Map class to hold names and values of Balance Sheet items
    map <int, float> TaxMap = {{1, 7500}, {2, 13750}, {3, 22250}, {4, 113900}, {5, 3400000}, 
				{6, 5150000}, {7, 8483333}};   //Map class to hold predetermined tax values



};

#endif 
