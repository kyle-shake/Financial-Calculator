/*
File: Bonds.cpp
Author: Kyle Shake

Last Modified: 12/7/17

*/

#include "Bonds.h"
#include "Annuities.h"
#include <cmath>


/*
 Bond Pricing:

 PVC is the Present Value of coupons
 PVV is the Present Value of Par|Face Value
 BV is the Bond Value

 NOTE: the variables for Cash Flows still hold (r, g, t, etc) 
 save for FV which is now the face|par value of the bond (usually $1000
 or in Treasury Quotations $10000)

 PVC = Annuity Equation
 PVV = Standard Present Value Equation
*/

Bonds::Bonds(){
    BV = 0;
    currYield = 0;
    ATR = 0;
    taxR = 0;
    accInterest = 0;
    cleanPrice = 0;
    dirtyPrice = 0;

}

// BV = PVC + PVV
float Bonds::BVCalc(float PVC, float PVV){
    BV = PVC + PVV;
}

//Current Yield = Annual Coupon / Price
float Bonds::currYieldCalc(float C, float price){
    currYield = C/price;
}

//After Tax Return(ATR) = r * (1 - tax rate)
float Bonds::ATRCalc(float r, float taxR){
    ATR = r * (1 - taxR);
}
//Tax Rate Indifference (calculating the tax rate where two bonds, one taxed & one untaxed, become equal)
// tax rate = -(r2 / r + 1)
float Bonds::taxRCalc(float r, float r2){
    taxR = -((r2/r) - 1);
}
//Clean Price = Cash (Dirty) Price - Accrued Interest
//Accrued Interest = C * (time since last payment/days in current payment period)
float Bonds::accInterestCalc(float C, float timeSinceC, float timeInPeriod){
    accInterest = C * (timeSinceC/timeInPeriod);
}

float Bonds::cleanPriceCalc(float dirtyPrice, float accInterest){
    cleanPrice = dirtyPrice - accInterest;
}
