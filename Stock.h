/*
File: Stock.h
Author: Kyle Shake

Last Modified: 12/7/17

*/



#ifndef STOCK_H
#define STOCK_H

#include "CashFlows.h"


class Stock: private CashFlows{

    public:
    Stock();
    void DGMCalc();


    private:
    float p0; //Stock Price at time 0
    float d[] //Dividends at time [0, 1, ..., n]
    

};

#endif
