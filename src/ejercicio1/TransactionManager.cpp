#include "ejercicio1/TransactionManager.h"

void Transaction::executeDeposit(Account* account, double amount) {
    if (account) {
        account->deposit(amount);
    }
}

void Transaction::executeWithdraw(Account* account, double amount) {
    if (account) {
        account->withdraw(amount);
    }
}

TransactionManager& TransactionManager::getInstance() {
    static TransactionManager instance; // Se inicializa solo una vez de forma thread-safe (C++11 en adelante)
    return instance;
}

void TransactionManager::deposit(Account* account, double amount) {
    Transaction::executeDeposit(account, amount);
}

void TransactionManager::withdraw(Account* account, double amount) {
    Transaction::executeWithdraw(account, amount);
}