/*
File: CashFlows.cpp
Author: Kyle Shake

Last Modified: 12/7/17


*/

#include "CashFlows.h"
#include <cmath>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <iostream>
#define MAX_CFs 100

using namespace std;

/*
Cash Flows

PV = Present Value, what future cash flows are worth today
FV = Future Value, what the cash flows are worth in the future
r is the interest rate, rate of return, or discount rate
g is the growth rate
t is the number of periods
C is the payment or coupon(for bonds) amount
*/


CashFlows::Cashflows(){
    CashFlows[MAX_CFs];
    PV = 0;
    FV = 0;
    r = 0;
    g = 0;
    t = 0;
    C = 0;
    APR = 0;
    EAR = 0;
    periodicRate = 0;
    m = 0;
}

//FV = PV * (1 + r)^t
void CashFlows::FVCalc(){
    FV = PV * pow((1 + r), t);
}

//PV = FV / (1 + r)^t
void CashFlows::PVCalc(){
    PV = FV / pow((1 + r), t);
}

//r = (FV/PV)^(1/t) - 1
void CashFlows::rCalc(){
    r = pow((FV/PV), (1/numofper)) - 1;
}

//t = ln(FV/PV) / ln(1 + r)
void CashFlows::tCalc(){
    t = log(FV/PV) / log(1 + r);
}

//PVIFA is the Annuity Present Value Factor
//PVIFA = (1 - 1/(1+r)^t)/r
void CashFlows::PVIFACalc(){
    PVIFA = (1 - (1/pow((1+r), t))) / r;
}

//FVIFA is the Annuity Future Value Factor
//FVIFA = ((1+r)^t - 1)/r
void CashFlows::FVIFACalc(){
    FVIFA = (pow((1 + r), t) - 1) / r;
}

/*
Annual Percentage Rate & Effective Annual Rate

  m is the number of compounding periods per year
  APR is the Annual Percentage Rate
  EAR is the Effective Annual Rate
*/
void APRCalc(){
    if(EAR == 0){
        APR = periodicRate * m;
    } else {
        APR = m * (pow((1 + EAR), 1/m) - 1);
    }
}

void periodicRateCalc(){
    periodicRate = APR / m;
}

void EARCalc(){
    EAR =  pow((1+periodicRate), m) - 1;
}

void EARContinuousCompoundingCalc(){
    EAR = exp(APR) - 1;
}
void APRContinuousCompoundingCalc(){
    APR = log(1+EAR);
}


