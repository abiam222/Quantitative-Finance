//
//  GenericInequalities.h
//  Templates
//
//  Created by Velazquez, Abiam (US - Orlando) on 6/19/16.
//  Copyright (c) 2016 Velazquez, Abiam (US - Orlando). All rights reserved.
//

#ifndef Templates_GenericInequalities_h
#define Templates_GenericInequalities_h

//Useful Functions

//Max and Min of two numbers
template <class Numeric>
    Numeric Max( const Numeric& x, const Numeric& y);
template <class Numeric>
    Numeric Min( const Numeric& x, const Numeric& y);

//Max and Min of three numbers
template <class Numeric>
    Numeric Max( const Numeric& x, const Numeric& y, const Numeric& z);
template <class Numeric>
    Numeric Min(const Numeric& x, const Numeric& y, const Numeric& z);


#endif
