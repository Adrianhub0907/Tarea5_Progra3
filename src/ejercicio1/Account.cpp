#include "ejercicio1/Account.h"
using namespace std;


Account::Account(const string& id, double initial_balance)
    : id(id), balance(initial_balance) {}

void Account::deposit(double amount) {
    lock_guard<std::mutex> lock(mtx);
    balance += amount;
}

void Account::withdraw(double amount) {
    lock_guard<std::mutex> lock(mtx);
    balance -= amount;
}

double Account::getBalance() const {
    lock_guard<std::mutex> lock(mtx);
    return balance;
}

string Account::getId() const {
    return id;
}