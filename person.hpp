//
//  person.hpp
//  Third Party Payroll Program
//
//  Created by Mina Moslehpour on 8/8/19.
//  Copyright © 2019 Mina Moslehpour. All rights reserved.
//

#ifndef person_hpp
#define person_hpp

#include <stdio.h>
#include <string>

using namespace std;

class person {
  
private:
    string _fname;
    string _lname;
    int _empID;
    string _company;
    float _hours;
    float _rate;
    
public:
    
    person();
    
    void setFname(string);
    string getFname();
    void setLname(string);
    string getLname();
    void setEmpID(int);
    int getEmpID();
    void setCompany(string);
    string getCompany();
    void setHours(float);
    float getHours();
    void setRate(float);
    float getRate();
    string fullName();
    float totalPay();
};

#endif /* person_hpp */
