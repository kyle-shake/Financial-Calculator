/*
File: Stock.cpp
Author: Kyle Shake

Last Modified: 12/7/17

*/


#include "Stock.cpp"

#define MAX_DIVS 100

/*
STOCK VALUATION EQUATIONS
p0 is the price of the stock at time 0
d0 is the dividend at time 0
d[n] is the dividend at time n
R is the discount rate or Required Rate of Return
g is the dividend growth rate

*/

Stock::Stock(){
    d[MAX_DIVS];
    p0 = 0;

}

void DGMcalc(){
    if ( R == 0 ){
        R = d[1]/p0 + g;
    }
    else if ( g == 0 ){ 
        g = d[1]/p0 - R;
    }
    else if ( p0 == 0){
        p0 = d[1]/(R-g);    
    }
    else if ( d[1]1 == 0){
        d[1] = p0*(R-g)
    }
}



