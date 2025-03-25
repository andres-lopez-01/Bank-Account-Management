#pragma once
#include <iostream>
using namespace std;


class BankAccount {
private:
	double balance;
	string accountNumber;
	bool isActive;

public:
	BankAccount() { //default constructor
		balance = 0;
		accountNumber = "0";
		isActive = true;
	}

	BankAccount(double balance, string accountNumber) { //constructor
		this->balance = balance;
		accountNumber = accountNumber;
		this->isActive = true;
	}

	void deposit(double amount); //adds funds to acc, if negative throw exception
	void widthdraw(double amount); //subtract funds from acc, if too much throw exception
	double getBalance() const; //returns the current balance
	void closeAccount(); //closes acc. once closed, all transactions should raise exception
}; 