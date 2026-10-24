#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "ejercicio3/Expression.h"
#include <cmath>
using namespace std;


class BinaryOperation : public Expression {
protected:
    shared_ptr<Expression> left;
    shared_ptr<Expression> right;

public:
    BinaryOperation(shared_ptr<Expression> l, shared_ptr<Expression> r)
        : left(move(l)), right(move(r)) {}
};

class Add : public BinaryOperation {
public:
    using BinaryOperation::BinaryOperation;

    double evaluate(double x) const override;
    shared_ptr<Expression> derivative() const override;
    string toString() const override;
};

class Multiply : public BinaryOperation {
public:
    using BinaryOperation::BinaryOperation;

    double evaluate(double x) const override;
    shared_ptr<Expression> derivative() const override;
    string toString() const override;
};

class Power : public BinaryOperation {
public:
    using BinaryOperation::BinaryOperation;

    double evaluate(double x) const override;
    shared_ptr<Expression> derivative() const override;
    string toString() const override;
};

class UnaryFunction : public Expression {
protected:
    shared_ptr<Expression> arg;

public:
    explicit UnaryFunction(shared_ptr<Expression> a) : arg(std::move(a)) {}
};

class Sin : public UnaryFunction {
public:
    using UnaryFunction::UnaryFunction;

    double evaluate(double x) const override;
    shared_ptr<Expression> derivative() const override;
    string toString() const override;
};

class Cos : public UnaryFunction {
public:
    using UnaryFunction::UnaryFunction;

    double evaluate(double x) const override;
    shared_ptr<Expression> derivative() const override;
    string toString() const override;
};

#endif