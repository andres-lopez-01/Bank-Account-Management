#include <iostream>
#include "BankAccountManagement.h"
#include "NegativeDepositException.h"
#include "OverdrawException.h"
using namespace std;

void displayWelcome(); //Displays Welcome when program starts
void displayMenu(); //Displys The Menu in Which user can interact 

int main() {
	double initialDepositAmount;

	displayWelcome();

	while (true) { //Chedcks for valid input
		try {
			cin >> initialDepositAmount;

			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw invalid_argument("That's not a valid number.");
			}

			if (initialDepositAmount < 0) { // Negative deposit check
				throw invalid_argument("Deposit cannot be negative.");
			}

			break; // Valid input, break out of loop
		}
		catch (const invalid_argument& e) {
			cout << e.what() << " Try Again: ";
		}
	}
	//Create Account
	auto account = make_unique<BankAccount>(initialDepositAmount, "123456");
	cout << "\nAccount Created Sucessfully!" << endl << endl;


	int userChoice;
	while (true){
		displayMenu(); // display the menu

		cin >> userChoice; // ask for user iunput

		if (cin.fail()) {// checks if input inp vvalid
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invaid input. PLease enter a number between 1 and 5." << endl;
			continue;//continue if input is a vvaliud number betwen 1 and 5
		}

		switch (userChoice) {//inpout from user
		case 1://case 1 (create account)
			cout << "\nCreating new account!" << endl;
			main();
			break;
		case 2://case 2 (check balance)
			cout << "\nChecking Account Balance." << endl;
			cout << "Balance: " << account->getBalance() << endl;
			break;
		case 3://case 3 (deposit amount)
			double depositAmount;
			cout << "\nEnter Amount to Deposit : ";
			cin >> depositAmount;

			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid input. Please enter a valid deposit amount.\n";
				break;
			}

			try {
				account->deposit(depositAmount);
			}
			catch (const NegativeDepositException& e) {
				cout << "Error: " << e.what() << endl;
			}
			break;
			cout << "Deposing Funds." << endl;
		case 4://case 4 (withdraw amount)
			double withdrawAmount;
			cout << "\nEnter amount to withdraw: ";
			cin >> withdrawAmount;

			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid input. Please enter a valid withdrawal amount.\n";
				break;
			}

			try {
				account->widthdraw(withdrawAmount);
			}
			catch (const invalid_argument& e) {
				cout << "Error: " << e.what() << endl;
			}
			catch (const OverdrawException& e) {
				cout << "Error: " << e.what() << endl;
			}
			break;
		case 5://case 5 (delete account)
			cout << "\nDeleting Account." << endl;
			account.reset();
			cout << "\nAccount Successfully Deleated. Exiting Program." << endl;
			return 0;
		default:
			cout << "Invalid option. Please select a number between 1 and 5" << endl; //ouput in number is invalid
		}
	} 
	


	return 0;
}

//display functions
void displayWelcome() {
	cout << "Welcome To Bank Account Management" << endl << endl;

	cout << "Enter The following Information to create Account!" << endl;
	cout << "Initial Deposit Amount: ";
}

void displayMenu() {
	cout << "\n--------Menu--------" << endl;
	cout << "(1) Create New Account" << endl;
	cout << "(2) Check Account Balance" << endl;
	cout << "(3) Deposit" << endl;
	cout << "(4) Widthdraw" << endl;
	cout << "(5) Delete Account" << endl;
	cout << "Select Option: ";
}