/*
File: Annuities.cpp
Author: Kyle Shake

Last Modified: 12/7/17

*/


#include "Annuities.h"
#include "CashFlows.h"
#include <cmath>


using namespace std;


Annuities::Annuity(){
    PVAnnuity = 0;
    FVAnnuity = 0;
    PVPerpetuity = 0;
}

//Ordinary Non-Growing Annuity: PV = C * PVIFA
//Ordinary Growing Annuity: PV = C * (1 - ( (1+g)/(1+r) )^t) / (r-g) 
//Annuity Due: PV = C * PVIFA * (1+r)
//Growing Annuity Due: PV = C * [(1 - ( (1+g)/(1+r) )^t / (r-g)] * (1+r)
void Annuities::PVAnnuityCalc(bool OrdinaryAnnuity){
    if (OrdinaryAnnuity){
        if (g == 0){
            PVAnnuity = C * PVIFA;
        } else {
            PVAnnuity = C * ((1 - pow( ((1+g)/(1+r)), t))/(r-g));
        }
    } else {
         if (g == 0){
            PVAnnuity = C * PVIFA  * (1 + r);
        } else {
            PVAnnuity = C * ((1 - pow(((1+g)/(1+r)), t))/(r-g)) * (1 + r);       
        }
    }
}

// Ordinary Annuity: FV = C * FVIFA
// Annuity Due: FV = C * FVIFA * (1+r)
void Annuities::FVAnnuityCalc(bool OrdinaryAnnuity){
    if(OrdinaryAnnuity){
        FVAnnuity = C * FVIFA
    } else {
        FVAnnuity = C * FVIFA * (1 + r);
    }
}

// C = PV / PVIFA
void Annuities::CCalc(){
    C = PV / PVIFA;

}
// PV of Non-Growing Perpetuity = C/r
// PV of Growing Perpetuity = C/r-g
void Annuities::PVPerpetuityCalc(){
    if(g == 0){
        PVPerpetuity = C / r;
    } else {
        PVPerpetuity = C / (r - g);
    }
}

//PV of Uneven Cash Flows = The Sum from i= 1 to n of Ci/(1+ri)^t
//12/7: NEEDS WORK
void Annuities::PVofUnevenCashFlowsCalc(){
    int n = (int) t;
    for (int i = 1; i <= n; i++){
        PV += CashFlows[i]/pow((1 + r), i);
    }
}


