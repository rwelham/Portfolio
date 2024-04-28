#include <iostream>
#include <string>
#include "AirgeadBankingHeader.h"

using namespace std;

//defining global variables
string inInvestment = "";
string inDeposit = "";
string inInterest = "";
double initialInvestment = -1;
double monthlyDeposit = -1;
double annualInterest = -1;
int numYears = -1;
string pressKey = "";

int main() {
	PrintInputHeader();

	//gets user input
	while (initialInvestment < 0) {
		cout << "Initial Investment Amount: " << endl;
		cin >> inInvestment;
		initialInvestment = stod(inInvestment.substr(1, inInvestment.length() - 1));
	}
	while (monthlyDeposit < 0) {
		cout << "Monthly Deposit: " << endl;
		cin >> inDeposit;
		monthlyDeposit = stod(inDeposit.substr(1, inDeposit.length() - 1));
	}
	while (annualInterest < 0) {
		cout << "Annual Interest: " << endl;
		cin >> inInterest;
		annualInterest = stod(inInterest.substr(1, inInterest.length()-1));
	}
	while (numYears < 0) {
		cout << "Number of years: " << endl;
		cin >> numYears;
	}

	//pause before continuing
	cout << "Press any letter and enter to continue . . ." << endl;
	cin >> pressKey;

	//prints results of money earned without a deposit
	PrintHeader("Without");
	PrintDetailsWithout(initialInvestment, annualInterest, numYears);
	cout << endl << endl;

	//prints results of money earned with a deposit
	PrintHeader("With");
	PrintDetailsWith(initialInvestment, monthlyDeposit, annualInterest, numYears);
	cout << endl << endl;


	return 0;
}