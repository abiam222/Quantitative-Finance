//
//  Person.cpp
//  Classes and Objects
//
//  Created by Velazquez, Abiam (US - Orlando) on 6/19/16.
//  Copyright (c) 2016 Velazquez, Abiam (US - Orlando). All rights reserved.
//

#include "Person.h"

//using namespace std;

Person::Person (const string& name, const DatasimDate& DateofBirth) {
    nam = name;
    dob = DateofBirth;
    createdB = DatasimDate();  //default today
}

void Person::print() {
    //Who am I?
    cout << "\n** Person Data **\ n";
    cout << "Name: " << nam << ", Date of birth: " << dob
        << ", Age: " << age() << endl;
}

void Person::age() const {
    return int( double(DatasimDate() - dob) / 365.0 );
}