#ifndef LEAVES_H
#define LEAVES_H

#include "ejercicio3/Expression.h"
using namespace std;

class Constant : public Expression {
private:
    double value;

public:
    explicit Constant(double val) : value(val) {}

    double evaluate(double x) const override {
        return value;
    }

    shared_ptr<Expression> derivative() const override {
        return make_shared<Constant>(0);
    }

    string toString() const override {
        if (value == static_cast<int>(value)) {
            return to_string(static_cast<int>(value));
        }
        return to_string(value);
    }
};

class Variable : public Expression {
public:
    Variable() = default;

    double evaluate(double x) const override {
        return x;
    }

    shared_ptr<Expression> derivative() const override {
        return make_shared<Constant>(1);
    }

    string toString() const override {
        return "x";
    }
};

#endif