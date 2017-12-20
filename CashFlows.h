/*
File: CashFlows.h
Author: Kyle Shake

Last Modified: 12/7/17



*/

#ifndef CASHFLOWS_H
#define CASHFLOWS_H

#include <string>
#include <map>


/*
Cash Flows

PV = Present Value, what future cash flows are worth today
FV = Future Value, what the cash flows are worth in the future
r is the interest rate, rate of return, or discount rate
g is the growth rate
t is the number of periods
C is the payment or coupon(for bonds) amount
*/


class CashFlows
{
    public:
    CashFlows();
    void FVCalc();
    void PVCalc();
    void rCalc();
    void tCalc();
    void PVIFACalc();
    void FVIFACalc();
    void APRCalc();
    void periodicRateCalc();
    void EARCalc();
    void EARContinuousCompoundingCalc();
    void APRContinuousCompoundingCalc();

    private:
    float CashFlows[];
    float PV;
    float FV;
    float r;
    float g;
    float t;
    float C;
    float APR; //Annual Percentage Rate
    float EAR; //Effective Annual Rate
    float periodicRate; //Rate per compounding period
    float m; //Number of compounding periods per year
 
};

#endif
