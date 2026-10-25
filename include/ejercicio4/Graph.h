#ifndef TAREA5_PROGRA3_GRAPH_H
#define TAREA5_PROGRA3_GRAPH_H

#include <map>
#include <list>
using namespace std;


struct Node {
    int id;
    list<int> nodos;
    Node(int val) : id(val) {}
};


class Graph {
    map<int, Node*> grafo;
public:
    ~Graph() {
        for (auto const& [key, val] : grafo) {
            delete val;
        }
        grafo.clear();
    }
    void addEdge(int x, int y){
        if (grafo.find(x) == grafo.end()) {
            grafo[x] = new Node(x);
        }

        if (grafo.find(y) == grafo.end()) {
            grafo[y] = new Node(y);
        }
        grafo[x]->nodos.push_back(y);
    }
    const std::list<int>& getNeighbors(int nodeId) const {
        return grafo.at(nodeId)->nodos;
    }
};






#endif //TAREA5_PROGRA3_GRAPH_H