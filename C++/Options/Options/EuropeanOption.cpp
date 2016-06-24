 ////
//  EuropeanOption.cpp
//  Options
//
//  Created by Velazquez, Abiam (US - Orlando) on 6/20/16.
//  Copyright (c) 2016 Velazquez, Abiam (US - Orlando). All rights reserved.
//

#include "EuropeanOption.h"
#include <math.h>

using namespace std;

#ifndef Pi
#define Pi 3.141592653589793238462643
#endif

double EuropeanOption::N(double x) const{
    double L, K, w ;
    /* constants */
    double const a1 = 0.31938153, a2 = -0.356563782, a3 = 1.781477937;
    double const a4 = -1.821255978, a5 = 1.330274429;
    
    L = fabs(x);
    K = 1.0 / (1.0 + 0.2316419 * L);
    w = 1.0 - 1.0 / sqrt(2 * Pi) * exp(-L *L / 2) * (a1 * K + a2 * K *K + a3 * pow(K,3) + a4 * pow(K,4) + a5 * pow(K,5));
    
    if (x < 0 ){
        w= 1.0 - w;
    }
    return w;
}

//Kernel Functions
double EuropeanOption::CallPrice() const {
    double tmp = sig * sqrt(T);
    
    double d1 = (log(U/K) + (b+(sig*sig)*0.5) * T) / tmp;  //Black Scholes equation
    double d2 = d1 - tmp;
    
   return (U * exp((b-r)*T) * N(d1)) - (K * exp(-r*T)* N(d2)); //Value of the call
}

double EuropeanOption::PutPrice() const {
    double tmp = sig * sqrt(T);
    
    double d1 = (log(U/K) + (b+(sig*sig)*0.5) * T) / tmp;  //Black Scholes equation
    double d2 = d1 - tmp;
   
    return (K * exp(-r*T)* N(-d2)) - (U * exp((b-r)*T) * N(-d1)); //Value of the call
}

double EuropeanOption::CallDelta() const {
    double tmp = sig * sqrt(T);
    
    double d1 = (log(U/K) + (b+(sig*sig)*0.5) * T) / tmp;  //Black Scholes equation

    return exp((b-r)*T) * (N(d1)-1.0);
}

void EuropeanOption::init() {
    //initialize all default values
    r = 0.08;
    sig = 0.30;
    K = 65.0;
    T = 0.25;
    U = 60.0; //U == STOCK in this case
    b = r; //black and shcoles stock option model
    optType = "C"; //European Call Option
}

void EuropeanOption::copy(const EuropeanOption &o2) {
    r = o2.r;
    sig = o2.sig;
    K = o2.K;
    T = o2.T;
    U = o2.U;
    b = o2.b;
    
    optType = o2.optType;
}

EuropeanOption::EuropeanOption() {
    //Defaultc call option
    init();
}

EuropeanOption::EuropeanOption(const EuropeanOption& o2) {
    //copy constructor
    copy(o2);
}

EuropeanOption::EuropeanOption(const string& optionType) {
    //Create option type
    init();
    optType = optionType;
    
    if (optionType == "c") {
        optType = "C";
    }
}

EuropeanOption::~EuropeanOption() {
    //Destructor
}

EuropeanOption& EuropeanOption::operator=(const EuropeanOption &opt2) {
    //Assignment operator (deep copy)
    if (this == &opt2) return * this;
    copy(opt2);
    return *this;
}

//Functoins that calculate option price and sensitivity
double EuropeanOption::Price() const {
    if (optType == "C") {
        return CallPrice();
    } else {
        return PutPrice();
    }
}

//Modifier functions
void EuropeanOption::toggle() {
    //change option type (C/P, P/C)
    if (optType == "C") {
        optType = "P";
    } else {
        optType = "C";
    }
}



