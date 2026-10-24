#include <iostream>
#include <vector>
#include <thread>
#include "ejercicio1/Account.h"
#include "ejercicio1/TransactionManager.h"
#include "ejercicio3/Expression.h"
#include "ejercicio3/Leaves.h"
#include "ejercicio3/Operations.h"

int main() {
    std::cout << " EJERCICIO 1 (SINGLETON) " << std::endl;
    auto& manager = TransactionManager::getInstance();
    Account account("A1", 1000);
    std::vector<std::thread> threads;

    for (int i = 0; i < 10; ++i) {
        threads.emplace_back([&]() {
            manager.deposit(&account, 100);
            manager.withdraw(&account, 50);
        });
    }

    for (auto& t : threads) t.join();

    std::cout << "Balance final: " << account.getBalance() << std::endl;
    std::cout << "Direccion manager: " << &TransactionManager::getInstance() << std::endl;

    std::cout << " EJERCICIO 3 (COMPOSITE) " << std::endl;
    auto x = std::make_shared<Variable>();

    auto expr = std::make_shared<Multiply>(
        std::make_shared<Add>(
            std::make_shared<Power>(x, std::make_shared<Constant>(2)),
            std::make_shared<Multiply>(std::make_shared<Constant>(3), x)
        ),
        std::make_shared<Sin>(x)
    );

    auto deriv = expr->derivative();

    std::cout << "f(x) = " << expr->toString() << std::endl;
    std::cout << "f'(x) = " << deriv->toString() << std::endl;
    std::cout << "f(2) = " << expr->evaluate(2) << std::endl;

    return 0;
}