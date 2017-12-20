/*
File: Bonds.h
Author: Kyle Shake


Last Modified: 12/7/17

*/

#ifndef BONDS_H
#define BONDS_H

#include "Annuities.h"

class Bonds: private CashFlows{
    public:
    Bonds();
    float BVCalc();
    float currYieldCalc();
    float ATRCalc();
    float taxRCalc();
    float accInterestCalc();
    float cleanPriceCalc();

    private:
    float BV;
    float currYield;
    float ATR;
    float taxR;
    float accInterest;
    float cleanPrice;
    float dirtyPrice;

};

#endif
