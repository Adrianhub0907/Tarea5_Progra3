#include <iostream>
#include <vector>
#include <thread>
#include "ejercicio1/Account.h"
#include "ejercicio1/TransactionManager.h"
#include "ejercicio3/Expression.h"
#include "ejercicio3/Leaves.h"
#include "ejercicio3/Operations.h"
using namespace std;


int main() {
    cout << " EJERCICIO 1 (SINGLETON) " << endl;
    auto& manager = TransactionManager::getInstance();
    Account account("A1", 1000);
    vector<std::thread> threads;

    for (int i = 0; i < 10; ++i) {
        threads.emplace_back([&]() {
            manager.deposit(&account, 100);
            manager.withdraw(&account, 50);
        });
    }

    for (auto& t : threads) t.join();

    cout << "Balance final: " << account.getBalance() << endl;
    cout << "Direccion manager: " << &TransactionManager::getInstance() << endl;

    cout << " EJERCICIO 3 (COMPOSITE) " << endl;
    auto x = make_shared<Variable>();

    auto expr = make_shared<Multiply>(
        make_shared<Add>(
            make_shared<Power>(x, make_shared<Constant>(2)),
            make_shared<Multiply>(make_shared<Constant>(3), x)
        ),
        make_shared<Sin>(x)
    );

    auto deriv = expr->derivative();

    cout << "f(x) = " << expr->toString() << endl;
    cout << "f'(x) = " << deriv->toString() << endl;
    cout << "f(2) = " << expr->evaluate(2) << endl;

    return 0;
}