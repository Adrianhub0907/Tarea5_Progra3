#include "ejercicio3/Operations.h"
#include "ejercicio3/Leaves.h"

// --- Add ---
double Add::evaluate(double x) const {
    return left->evaluate(x) + right->evaluate(x);
}

std::shared_ptr<Expression> Add::derivative() const {
    return std::make_shared<Add>(left->derivative(), right->derivative());
}

std::string Add::toString() const {
    return "(" + left->toString() + " + " + right->toString() + ")";
}

// --- Multiply ---
double Multiply::evaluate(double x) const {
    return left->evaluate(x) * right->evaluate(x);
}

// Regla del producto: (u*v)' = u'*v + u*v'
std::shared_ptr<Expression> Multiply::derivative() const {
    auto term1 = std::make_shared<Multiply>(left->derivative(), right);
    auto term2 = std::make_shared<Multiply>(left, right->derivative());
    return std::make_shared<Add>(term1, term2);
}

std::string Multiply::toString() const {
    return "(" + left->toString() + " * " + right->toString() + ")";
}

// --- Power ---
double Power::evaluate(double x) const {
    return std::pow(left->evaluate(x), right->evaluate(x));
}

// Derivada simplificada para x^n alineada con POO básica: n * x^(n-1) * x'
std::shared_ptr<Expression> Power::derivative() const {
    // Tomamos el valor constante del exponente
    auto nConst = std::dynamic_pointer_cast<Constant>(right);
    double n = nConst ? nConst->evaluate(0) : 2.0;

    auto newExp = std::make_shared<Constant>(n - 1);
    auto powTerm = std::make_shared<Power>(left, newExp);
    auto multCoeff = std::make_shared<Multiply>(right, powTerm);

    return std::make_shared<Multiply>(multCoeff, left->derivative());
}

std::string Power::toString() const {
    return "(" + left->toString() + "^" + right->toString() + ")";
}

// --- Sin ---
double Sin::evaluate(double x) const {
    return std::sin(arg->evaluate(x));
}

// Regla de la cadena: sin(u)' = cos(u) * u'
std::shared_ptr<Expression> Sin::derivative() const {
    return std::make_shared<Multiply>(std::make_shared<Cos>(arg), arg->derivative());
}

std::string Sin::toString() const {
    return "sin(" + arg->toString() + ")";
}

// --- Cos ---
double Cos::evaluate(double x) const {
    return std::cos(arg->evaluate(x));
}

// Regla de la cadena: cos(u)' = -sin(u) * u'
std::shared_ptr<Expression> Cos::derivative() const {
    auto negOne = std::make_shared<Constant>(-1);
    auto negSin = std::make_shared<Multiply>(negOne, std::make_shared<Sin>(arg));
    return std::make_shared<Multiply>(negSin, arg->derivative());
}

std::string Cos::toString() const {
    return "cos(" + arg->toString() + ")";
}