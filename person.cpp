//
//  person.cpp
//  Third Party Payroll Program
//
//  Created by Mina Moslehpour on 8/8/19.
//  Copyright © 2019 Mina Moslehpour. All rights reserved.
//

#include "person.hpp"
#include <string>

using namespace std;

person::person() {
    _lname = " ";
    _fname = " ";
    _company = " ";
    _empID = 0;
    _rate = 0.0;
    _hours = 0.0;
}

person::person(string lname) {
    _lname = lname;
    _fname = " ";
    _company = " ";
    _empID = 0;
    _rate = 0.0;
    _hours = 0.0;
}

void person::setLname(string lname) {
    _lname = lname;
}

void person::setFname(string fname) {
    _fname = fname;
}
void person::setCompany(string company) {
    _company = company;
}
void person::setEmpID(int empID) {
    _empID = empID;
}

void person::setRate(float rate) {
    _rate = rate;
}

void person::setHours(float hours) {
    _hours = hours;
}

string person::getLname() {
    return _lname;
}

string person::getFname(){
    return _fname;
}
string person::getCompany(){
    return _company;
}
int person::getEmpID(){
    return _empID;
}

float person::getRate() {
    return _rate;
}

float person::getHours() {
    return _hours;
}

float person::totalPay() {
    return _hours * _rate;
}

string person::fullName() {
    return _fname + " " + _lname;
}
