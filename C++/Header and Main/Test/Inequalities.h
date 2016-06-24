//
//  Inequalities.h
//  Test
//
//  Created by Velazquez, Abiam (US - Orlando) on 6/19/16.
//  Copyright (c) 2016 Velazquez, Abiam (US - Orlando). All rights reserved.
//

#ifndef Test_Inequalities_h
#define Test_Inequalities_h

//
double Max( double x, double y);
double Min( double x, double y);
double Max( double x, double y, double z);
double Min( double x, double y, double z);

//Max and Min of two numbers
double Max( double x, double y ) {
    if (x > y) return x;
    
    return y;
}

double Min( double x, double y ) {
    if ( x < y ) return x;
    
    return y;
}

//Max and Min of three numbers
double Max( double x, double y, double z ) {
    return Max(Max(x,y), z);
}

double Min( double x, double y, double z ) {
    return Min(Min(x,y), z);
}

#endif
