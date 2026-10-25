#ifndef TAREA5_PROGRA3_ITERATORS_H
#define TAREA5_PROGRA3_ITERATORS_H

#include "Graph.h"
#include <queue>
#include <stack>
#include <set>

class GraphIterator {
public:
    virtual ~GraphIterator() = default;
    virtual bool hasNext() = 0;
    virtual int next() = 0;
};

class BFSIterator: public GraphIterator{
private:
    const Graph& grafo;
    std::queue<int> q;
    std::set<int> visited;
public:
    BFSIterator(const Graph& g, int startNode) : grafo(g) {
        q.push(startNode);
        visited.insert(startNode);
    }

    bool hasNext() override {
        return !q.empty();
    }

    int next() override {
        int current = q.front();
        q.pop();
        for (int neighbor : grafo.getNeighbors(current)) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                q.push(neighbor);
            }
        }
        return current;
    }
};

class DFSIterator:public GraphIterator {
private:
    const Graph& grafo;
    std::stack<int> s;
    std::set<int> visited;

public:
    DFSIterator(const Graph& g, int startNode) : grafo(g) {
        s.push(startNode);
        visited.insert(startNode);
    }

    bool hasNext() override {
        return !s.empty();
    }

    int next() override {
        int current = s.top();
        s.pop();
        for (int neighbor : grafo.getNeighbors(current)) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                s.push(neighbor);
            }
        }
        return current;
    }
};

#endif //TAREA5_PROGRA3_ITERATORS_H