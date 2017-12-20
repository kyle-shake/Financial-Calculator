/*
File: Annuities.h
Author: Kyle Shake

Last Modified: 12/7/17


*/
#ifndef ANNUITIES_H
#define ANNUITIES_H

#include "CashFlows.h"

using namespace std;

class Annuity: private CashFlows{
    friend class Bond;
    public:
    Annuity();
    void PVAnnuityCalc();
    void FVAnnuityCalc();
    void CCalc();
    void PVPerpetuityCalc();

    protected:
    float PVAnnuity;
    float FVAnnuity;
    float PVPerpetuity;
};

#endif
