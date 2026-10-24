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
    // Constructor privado para evitar instanciación externa
    TransactionManager() = default;
    ~TransactionManager() = default;

public:
    // Eliminar copia y asignación
    TransactionManager(const TransactionManager&) = delete;
    TransactionManager& operator=(const TransactionManager&) = delete;

    // Singleton Thread-Safe (Meyers' Singleton)
    static TransactionManager& getInstance();

    void deposit(Account* account, double amount);
    void withdraw(Account* account, double amount);
};

#endif