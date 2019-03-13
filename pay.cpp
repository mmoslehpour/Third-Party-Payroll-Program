// pay.cpp

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <iomanip>
#include "person.cpp"
using namespace std;


void readData (vector <Person> &employees);
void getCompanies (vector <string> &companyNames, vector<Person> &employees);
void printHighestPaid (vector <Person> &employees);
void separateAndSave (vector<string> &companyNames, vector<Person> &employees);


int main() {

	ifstream file;
	int n = 0;

	// declearing vector
	vector <Person> employees;
	vector <string> companyNames;

	readData (employees);
	getCompanies (companyNames, employees);
	printHighestPaid(employees);
	separateAndSave (companyNames, employees);


}

// read the data from “input.txt” and store it in the employees vector
void readData (vector <Person> &employees) {

	string fName, lName, coName;
	int id;
	float rate, hours;

	// open file
	ifstream file;
	file.open("input.txt");

	// if fail to open file
	if (!file) {
		cout << "Fail to open file. " << endl;
		exit(1);
	}

	// while theres info in file
	while (file >> fName >> lName >> id >> coName >> rate >> hours) {
		Person p;
		p.setFirstName (fName);
		p.setLastName (lName);
		p.setEmployeeId (id);
		p.setCompanyName (coName);
		p.setPayRate (rate);
		p.setHoursWorked (hours);
		// save all info to end of vector
		employees.push_back(p);

	}
	file.close();

}

// holds the string names of each company
void getCompanies (vector <string> &companyNames, vector<Person> &employees)  {

	string company;

	//  if theres still info
	for (int i = 0; i < employees.size(); i++) {
		// read and get company name matching to employees
		company = employees.at(i).getCompanyName();
		// save name and company name to end of vector
		companyNames.push_back(company);
	}
}

// find and output the full name, employee ID, company name, and total pay of the person who was paid the highest amount this statement
void printHighestPaid (vector <Person> &employees) {
	
	int max = 0;

	for (int i = 0; i < employees.size(); i++) {
		// comparing employees pay and find the highest
		if (employees.at(max).totalPay() < employees.at(i).totalPay())
			max = i;

	}
	cout << "Highest Paid: " << employees.at(max).fullName() << endl;
	cout << "Employee ID: " << employees.at(max).getEmployeeId() << endl;
	cout << "Employer: " << employees.at(max).getCompanyName() << endl;
	cout << "Total Pay: $" << employees.at(max).totalPay() << endl;

}

void separateAndSave (vector<string> &companyNames, vector<Person> &employees) {
	// read all company names
	for (int i = 0; i < companyNames.size(); i++) {

		float total = 0.0;
		
		ofstream file;
		file.open(companyNames[i]+ ".txt" );

		file << companyNames[i] << ".txt" << endl;
		file << "--------------------------------------------------------------" << endl;
		// read all info
		for (int j = 0; j < employees.size(); j++) {
			// if name matches info, write file
			if ( companyNames[i] == employees[j].getCompanyName()) {

				file << setw(20) << left << employees[j].fullName() << " " ;
				file << setw(10) << right << employees[j].getEmployeeId() << " "  ;
				file << setw(10)  << employees[j].getCompanyName() << " " ;
				file << setw(10)  << employees[j].totalPay() << endl;
				total += employees[j].totalPay();
			}

		}
		file << endl;
		file << "Total $" << total << endl;
		
	}

}
