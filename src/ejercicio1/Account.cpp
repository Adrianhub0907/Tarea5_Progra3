#include "ejercicio1/Account.h"

Account::Account(const std::string& id, double initial_balance)
    : id(id), balance(initial_balance) {}

void Account::deposit(double amount) {
    std::lock_guard<std::mutex> lock(mtx);
    balance += amount;
}

void Account::withdraw(double amount) {
    std::lock_guard<std::mutex> lock(mtx);
    balance -= amount;
}

double Account::getBalance() const {
    std::lock_guard<std::mutex> lock(mtx);
    return balance;
}

std::string Account::getId() const {
    return id;
}