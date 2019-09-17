//
//  main.cpp
//  Third Party Payroll Program
//
//  Created by Mina Moslehpour on 8/8/19.
//  Copyright © 2019 Mina Moslehpour. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "person.hpp"

using namespace std;

void readData(vector<person> &employees) {
    string fname, lname, company;
    int empID;
    float rate, hours;
    person p;
 //   person *p;
   // p = new person();
    
    ifstream file;
    file.open("input.txt");
    
    if(!file){
        cout << "File not found. " << endl;
    }
    
    while(!file.eof()) {
        file >> fname >> lname >> empID >> company >> rate >> hours;
        
        p.setFname(fname);
        p.setLname(lname);
        p.setEmpID(empID);
        p.setCompany(company);
        p.setRate(rate);
        p.setHours(hours);
        
        //person p(fname, lname, empID, company, rate, hours);
        
        employees.push_back(p);  // push back all info in p into employees vector
    }
    
    file.close();
}

void getCompName(vector<person> employees, vector<string> &companies) {
    for(int i = 0; i < employees.size(); i++) {
        companies.push_back(employees.at(i).getCompany()); // push back all company name we got from file in employees vector into companies vector
    }
}

void printHighest(vector<person> employees) {
    int max = 0;
    
    for (int i = 0; i < employees.size(); i++) {
        if(employees.at(max).totalPay() < employees.at(i).totalPay()) { // if MAX < i, MAX = i
            max = i;
        }
    }
    cout << " ***** Higest Paid ***** " << endl;
    cout << "Compnay: " << employees.at(max).getCompany() << endl;
    cout << "Employee ID: " << employees.at(max).getEmpID() << endl;
    cout << "Employee Name: " << employees.at(max).fullName() << endl;
    cout << "Total Pay $" << employees.at(max).totalPay() << endl;
    cout << endl;
}

void sepAndSave(vector<person> &employees, vector<string> &companies) {
    
    for(int j = 0; j < employees.size(); j++) {
        
        ofstream file(companies.at(j) + ".txt");
        
        
        
        for(int i = 0; i < employees.size(); i++) {
            if(companies.at(i) == employees.at(j).getCompany()) {
                file << employees.at(i).fullName() << " ";
                file << employees.at(i).getEmpID() << " ";
                file << employees.at(i).getCompany() << " ";
                file << "$" << employees.at(i).totalPay() << endl;
            }
        }
        file.close();
    }
}


int main() {
    vector<person> employees;
    vector<string> companies;
    
    readData(employees);
    getCompName(employees, companies);
    printHighest(employees);
    sepAndSave(employees, companies);
}
