//
//  main.cpp
//  Templates
//
//  Created by Velazquez, Abiam (US - Orlando) on 6/19/16.
//  Copyright (c) 2016 Velazquez, Abiam (US - Orlando). All rights reserved.
//

#include <iostream>
#include "GenericInequalities.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    int d1,d2;
    cout << "Give the first number: ";
    cin >> d1;
    cout << "Give the second number: ";
    cin >> d2;
    
    char c; //character type
    cout << "Which function a) Max() or b) Min()?";
    cin >> c;
    
    if ( c == 'a' ) {
        cout << "Max value is: " << Max<int>(d1, d2) << endl;
    } else {
        cout << "Min value is: " << Min<int>(d1, d2) << endl;
    }
    
    long dA = 12334; long dB = 2; long dC = -3;
    cout << "\n\nMax and min of three numbers: " << endl;
    cout << "Max value is: " << Max<long>(dA, dB, dC) << endl;
    cout << "Min value is: " << Min<long>(dA, dB, dC) << endl;
    
    return 0;
}
