#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <memory>
#include <string>
using namespace std;

class Expression {
public:
    virtual ~Expression() = default;
    virtual double evaluate(double x) const = 0;
    virtual shared_ptr<Expression> derivative() const = 0;
    virtual string toString() const = 0;
};

#endif