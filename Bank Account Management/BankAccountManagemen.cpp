#include "BankAccountManagement.h"
#include "OverdrawException.h"
#include "NegativeDepositException.h"
#include <memory>

void BankAccount::deposit(double amount) { //adds funds to acc, if negative throw exception
    if (!isActive) {
        throw runtime_error("Cannot deposit. Account is closed.");
    }
    if (amount <= 0) {
        throw NegativeDepositException("Deposit amount must be greater than zero.");
    }

    balance += amount;
    cout << "Deposit successful! New balance: $" << balance << endl;
}

void BankAccount::widthdraw(double amount) { //subtract funds from acc, if too much throw exception
    if (!isActive) {
        throw runtime_error("Cannot withdraw. Account is closed.");
    }
    if (amount <= 0) {
        throw invalid_argument("Withdrawal amount must be greater than zero.");
    }
    if (amount > balance) {
        throw OverdrawException("Insufficient funds for this withdrawal.");
    }

    balance -= amount;
    cout << "Withdrawal successful! New balance: $" << balance << endl;
}

double BankAccount::getBalance() const { //returns the current balance
    if (!isActive) {
        throw runtime_error("Cannot check balance. Account is closed.");
    }
    return balance;
}

void BankAccount::closeAccount() { //closes acc. once closed, all transactions should raise exception
    isActive = false;
    cout << "account closed";
}