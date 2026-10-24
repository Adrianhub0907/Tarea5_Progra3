#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "ejercicio3/Expression.h"
#include <cmath>

// Operación Binaria Base
class BinaryOperation : public Expression {
protected:
    std::shared_ptr<Expression> left;
    std::shared_ptr<Expression> right;

public:
    BinaryOperation(std::shared_ptr<Expression> l, std::shared_ptr<Expression> r)
        : left(std::move(l)), right(std::move(r)) {}
};

// Suma (+)
class Add : public BinaryOperation {
public:
    using BinaryOperation::BinaryOperation;

    double evaluate(double x) const override;
    std::shared_ptr<Expression> derivative() const override;
    std::string toString() const override;
};

// Multiplicación (*)
class Multiply : public BinaryOperation {
public:
    using BinaryOperation::BinaryOperation;

    double evaluate(double x) const override;
    std::shared_ptr<Expression> derivative() const override;
    std::string toString() const override;
};

// Potencia (x^n)
class Power : public BinaryOperation {
public:
    using BinaryOperation::BinaryOperation;

    double evaluate(double x) const override;
    std::shared_ptr<Expression> derivative() const override;
    std::string toString() const override;
};

// Función Unaria Base
class UnaryFunction : public Expression {
protected:
    std::shared_ptr<Expression> arg;

public:
    explicit UnaryFunction(std::shared_ptr<Expression> a) : arg(std::move(a)) {}
};

// Seno: sin(x)
class Sin : public UnaryFunction {
public:
    using UnaryFunction::UnaryFunction;

    double evaluate(double x) const override;
    std::shared_ptr<Expression> derivative() const override;
    std::string toString() const override;
};

// Coseno: cos(x) [Necesario para la derivada del Seno]
class Cos : public UnaryFunction {
public:
    using UnaryFunction::UnaryFunction;

    double evaluate(double x) const override;
    std::shared_ptr<Expression> derivative() const override;
    std::string toString() const override;
};

#endif