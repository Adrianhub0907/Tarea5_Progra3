#ifndef TRANSACTION_MANAGER_H
#define TRANSACTION_MANAGER_H

#include "ejercicio1/Account.h"


class Transaction {
public:
    static void executeDeposit(Account* account, double amount);
    static void executeWithdraw(Account* account, double amount);
};

class TransactionManager {
private:
    TransactionManager() = default;
    ~TransactionManager() = default;

public:
    TransactionManager(const TransactionManager&) = delete;
    TransactionManager& operator=(const TransactionManager&) = delete;

    static TransactionManager& getInstance();

    void deposit(Account* account, double amount);
    void withdraw(Account* account, double amount);
};

#endif