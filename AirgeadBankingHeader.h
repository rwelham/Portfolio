#pragma once
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


//outputs a string of a specified character a specified number of times
string RepeatChars(char printChar, unsigned int num) {
	string outString = ""; //output string
	//loops the number of times input and prints the character on the same line for the specified times
	for (unsigned int i = 0; i < num; i++) {
		outString += printChar;
	}
	return outString; //returns the string
}

//prints initial input header
void PrintInputHeader() {
	cout << RepeatChars('*', 80) << endl;
	cout << RepeatChars('*', 34)  << " Data Input " << RepeatChars('*',34
	) << endl;
}

//returns monthly interest based on open amount, deposited amount, and annual interest
double CalculateMonthlyInterest(double initialAmount, double addedAmount, double annualInterest) {
	return (initialAmount + addedAmount) * ((annualInterest / 100) / 12);
}

// prints the header text for the balance both with and without monthly deposits
void PrintHeader(string str) {
	cout << RepeatChars('+', 80) << endl;
	cout << "           Balance and Interest " << str << " Additional Monthly Deposits   " << endl;
	cout << RepeatChars('+', 80) << endl;
	cout << "   Year              Year End Balance               Year End Earned Interest    " << endl;
	cout << RepeatChars('-', 80) << endl;
}

//calculates a year's balance without any deposits
double BalanceWithoutMonthly(double currAmount, double interest) {
	double yearlyBalance = 0;
	//loops through 12 times for 12 months in a year, adding the current amount and any interest earned
	for (int i = 0; i < 12; i++) {
		yearlyBalance = currAmount + CalculateMonthlyInterest(currAmount, 0, interest);
		currAmount = yearlyBalance;
	}
	return yearlyBalance;
}

//calculates a year's balance with monthly deposits
double BalanceWithMonthly(double currAmount, double monthlyAmount, double interest) {
	double yearlyBalance = 0;
	//loops for the twelve months adding the current month's amount, the monthly deposit, and the interest earned
	for (int i = 0; i < 12; i++) {
		yearlyBalance = currAmount + monthlyAmount + CalculateMonthlyInterest(currAmount, monthlyAmount, interest);
		currAmount = yearlyBalance;
	}
	return yearlyBalance;
}

//loops through the number of years desired with the initial amount and interest earned with NO monthly deposit
void PrintDetailsWithout(double initAmount, double interest, int numYears) {
	double previousYear = initAmount;
	double currentAmount = 0;
	//loops through the number of years
	for (int year = 1; year <= numYears; year++) {
		//prints year, the year's current amount, and the year's earned interest
		cout << "    " << year << "                       $";
		currentAmount = BalanceWithoutMonthly(previousYear, interest);
		cout << fixed << setprecision(2) <<currentAmount << "                           $"
			 << currentAmount - previousYear << endl << endl;
		previousYear = currentAmount;
	}
}

//loops through the number of years desired with the initial amount, the monthly deposit, and interest earned
void PrintDetailsWith(double initAmount, double monthlyDeposit, double interest, int numYears) {
	double previousYear = initAmount;
	double currentAmount = 0;
	double depositAmount = monthlyDeposit * 12; //for subtracting the yearly amount deposited
	//loops through the number of years
	for (int year = 1; year <= numYears; year++) {
		//prints what year it is, the end of the year balance, and the interest earned
		cout << "    " << year << "                       $";
		currentAmount = BalanceWithMonthly(previousYear, monthlyDeposit, interest);
		cout << fixed << setprecision(2) << currentAmount << "                           $"
			<< currentAmount - previousYear - depositAmount << endl << endl; // prints the end year balance and interest earned
		previousYear = currentAmount;
	}
}