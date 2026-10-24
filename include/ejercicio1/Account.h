#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <mutex>

class Account {
private:
    std::string id;
    double balance;
    mutable std::mutex mtx;

public:
    Account(const std::string& id, double initial_balance);

    void deposit(double amount);
    void withdraw(double amount);
    double getBalance() const;
    std::string getId() const;
};

#endif