// person.cpp


#include <iostream>
using namespace std;
#include "person.h"

// defalut contructor
Person::Person() {

}

//overloaded contructor

// first name
void Person::setFirstName (string fName) {
	firstName = fName;
}

string Person::getFirstName() {
    return firstName;
}

// last name
void Person::setLastName (string lName) {
	lastName = lName;
}

string Person::getLastName() {
    return lastName;
}

// employee ID
void Person::setEmployeeId (int id) {
	employeeId = id;
}

int Person::getEmployeeId() {
	return employeeId;
}

// company name
void Person::setCompanyName (string coName) {
	companyName = coName;
}

string Person::getCompanyName () {
	return companyName;
}

// pay rate
void Person::setPayRate (float rate) {
	payRate = rate;
}

float Person::getPayRate () {
	return payRate;
}

// hours worked
void Person::setHoursWorked (float hours) {
	hoursWorked = hours;
}

float Person::getHoursWorked () {
	return hoursWorked;
}

// totalpay
float Person::totalPay() {
    return hoursWorked * payRate;
}

// full name
string Person::fullName() {
    return firstName + " " + lastName;
}