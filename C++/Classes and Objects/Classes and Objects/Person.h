//
//  Person.h
//  Classes and Objects
//
//  Created by Velazquez, Abiam (US - Orlando) on 6/19/16.
//  Copyright (c) 2016 Velazquez, Abiam (US - Orlando). All rights reserved.
//

#ifndef Classes_and_Objects_Person_h
#define Classes_and_Objects_Person_h

//#include "datasimdate.h"
#include <string>

using namespace std;

class Person {
    public: //Everything public, for convinience only
    
        //Data
        string nam;//name of person
        DatasimDate dob; //date of birth
        DatasimData createdB; //when object was created
    
    public:
        Person (const string& name, const DatasimDate& DateofBirth);
        void print() const;
        int age() const;
};


#endif
