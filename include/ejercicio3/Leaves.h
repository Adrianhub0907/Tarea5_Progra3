#ifndef LEAVES_H
#define LEAVES_H

#include "ejercicio3/Expression.h"

class Constant : public Expression {
private:
    double value;

public:
    explicit Constant(double val) : value(val) {}

    double evaluate(double x) const override {
        return value;
    }

    std::shared_ptr<Expression> derivative() const override {
        return std::make_shared<Constant>(0);
    }

    std::string toString() const override {
        if (value == static_cast<int>(value)) {
            return std::to_string(static_cast<int>(value));
        }
        return std::to_string(value);
    }
};

class Variable : public Expression {
public:
    Variable() = default;

    double evaluate(double x) const override {
        return x;
    }

    std::shared_ptr<Expression> derivative() const override {
        return std::make_shared<Constant>(1);
    }

    std::string toString() const override {
        return "x";
    }
};

#endif