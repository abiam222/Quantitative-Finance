//
//  main.cpp
//  C++ examples
//
//  Created by Velazquez, Abiam (US - Orlando) on 6/20/16.
//  Copyright (c) 2016 Velazquez, Abiam (US - Orlando). All rights reserved.
//

#include <iostream>

using namespace std;


//EXAMPLE2
class SampleClass {

public:
    //for convenience only
    //thid data is created at compile time
    double contents[1000];
    
public:
    SampleClass(double d) {
        for (int i =0; i < 1000; i++) {
            contents[i] = d;
        }
    }
    
    virtual ~SampleClass() {
        cout << "SampleClass instance being deleted \n";
    }
    
};

//EXAMPLE 1
//double Max(double x, double y) {
//    if (x > y) {
//        return x;
//    }
//    return y;
//}

//EXAMPLE2
double Sum(SampleClass myClass) {
    double result = myClass.contents[0];
    for (int i=1; i<1000; i++) {
        result += myClass.contents[i];
    }
    return result;
}


//EXAMPLE2
/*
 Here we are working directly with the address of the input parameter
 and not a copy of it.  We are working with the 'live' object and it is
 in fact possible to modify it in the body of the function that it is
 being used in.  
 */
double Sum2(SampleClass& myClass){
    double result = myClass.contents[0];
    for (int i=1; i<1000; i++) {
        result += myClass.contents[i];
    }
    return result;
}


int main(int argc, const char * argv[]) {

//EXAMPLE 1 (pass by value)
//    double d1 = 1.0;
//    double d2 = -34536.00;
//    //Copies of d1 and d2 offered to the function Max()
//    double result = Max(d1,d2);
//    cout << "Maxvalue is " << result << endl;
    
//EXAMPLE 2
    SampleClass sc(1.0);
    double sum = Sum(sc);
    cout << sum << endl;
    //What's happening here is that a copy of sc will be created and this is the object
    //the function will work on.  The code works correctly but it is not efficient.  We
    //circumvent this problem by using object addresses and the call by reference technique
    //(in new method called Sum2)
    
    return 0;
}


//NOTES
/*
**You can use call-by-value or call-by-reference for any type or class but in general 
I use the former for built-in types while I use the latter for objects and class instances
**I try to avoid using pointers as input parameters to functoins and we shall discuss why
in a later chapter.  By this statement we mean a function prototype having the following
signature
double Sum2(SampleClass* myClass);
This is the style reminiscent of bygone days and we advise against its use.  we use modern
C++ syntax and in this sense it is a "better C"
**When using call-by-reference it is only necessary to declare an object once as an address
while in a main program you can use it as a 'normal' object (that is, without having to use
'&')
*/