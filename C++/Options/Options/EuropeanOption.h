//
//  EuropeanOption.h
//  Options
//
//  Created by Velazquez, Abiam (US - Orlando) on 6/20/16.
//  Copyright (c) 2016 Velazquez, Abiam (US - Orlando). All rights reserved.
//

#ifndef __Options__EuropeanOption__
#define __Options__EuropeanOption__

#include <stdio.h>
#include <string>

using namespace std;

class EuropeanOption {

private:
    void init(); //initialize all default values
    void copy(const EuropeanOption& o2); //kernel functions for option calculations
    double CallPrice() const;
    double PutPrice() const;
    double CallDelta() const;
    double PutDelta() const;
   
public:
    double r; // interest rate
    double sig; //volatility
    double K; //strike price
    double T; //expiration date
    double U; //current underlying price
    double b; //cost of carry
    
    string optType; //Option name (call and put)
    
public:
    //Constructors
    EuropeanOption(); //Default call option
    EuropeanOption(const EuropeanOption& option2); //copy constructor
    EuropeanOption(const string& optionType); //create option type
    
    //Destructor
    virtual ~EuropeanOption();
    
    //Assignment Operator
    EuropeanOption& operator = (const EuropeanOption& option2);
    
    //Functions that calculate option price and some sensitivities
    double Price() const;
    double Delta() const;
    double N(double x) const;//Normal Distribution function to grab
    //probability given my z score and (why does this also have to be
    //const to be used in other const functions???
    
    //MOdifier functions
    void toggle(); //Change option type (C/P, P/C)
};

#endif /* defined(__Options__EuropeanOption__) */
