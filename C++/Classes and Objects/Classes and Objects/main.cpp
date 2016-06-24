//
//  main.cpp
//  Classes and Objects
//
//  Created by Velazquez, Abiam (US - Orlando) on 6/19/16.
//  Copyright (c) 2016 Velazquez, Abiam (US - Orlando). All rights reserved.
//

#include <iostream>
#include <string>
//#include "datasimdate.h"
#include "Person.h"


using namespace std;

int main(int argc, const char * argv[]) {
  
    DatasimDate myBirthday(29, 8, 1952);
    string myName ("Daniel J. Duffy");
    Person dd(myName, myBirthday);
    dd.print();
    
    DatasimDate bBirthday(06, 8, 1994);
    string bName ("Brendan Duffy");
    Peson bd(bName, bBirthday);
    bd.print();
    
    return 0 ;
}
