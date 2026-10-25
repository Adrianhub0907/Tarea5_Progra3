#include <iostream>
#include <vector>
#include <thread>
#include "ejercicio1/Account.h"
#include "ejercicio1/TransactionManager.h"
#include "ejercicio2/RenderFactory.h"
#include "ejercicio2/Elementos.h"
#include "ejercicio3/Expression.h"
#include "ejercicio3/Leaves.h"
#include "ejercicio3/Operations.h"
#include "ejercicio4/Graph.h"
#include "ejercicio4/Iterators.h"
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

    cout << " Ejercicio 2 (Abstract factory) " << endl;
    std::unique_ptr<RenderFactory> factory =
    std::make_unique<OpenGLFactory>();
    auto window = factory->createWindow();
    auto button = factory->createButton();
    auto shader = factory->createShader();
    window->draw();
    button->draw();
    shader->compile();
    factory = std::make_unique<VulkanFactory>();
    window = factory->createWindow();
    button = factory->createButton();
    shader= factory->createShader();
    window->draw();
    button->draw();
    shader->compile();

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

    cout << " Ejercicio 4 (Iterator) " << endl;
    Graph g;
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    std::unique_ptr<GraphIterator> it =
    std::make_unique<BFSIterator>(g, 1);
    while(it->hasNext()) {
        std::cout << it->next() << " ";
    }
    std::cout << endl;
    std::unique_ptr<GraphIterator> it2 =
    std::make_unique<DFSIterator>(g, 1);
    while(it2->hasNext()) {
        std::cout << it2->next() << " ";
    }
    return 0;
}