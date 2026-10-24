#include "ejercicio3/Operations.h"
#include "ejercicio3/Leaves.h"
using namespace std;


double Add::evaluate(double x) const {
    return left->evaluate(x) + right->evaluate(x);
}

shared_ptr<Expression> Add::derivative() const {
    return make_shared<Add>(left->derivative(), right->derivative());
}

string Add::toString() const {
    return "(" + left->toString() + " + " + right->toString() + ")";
}


double Multiply::evaluate(double x) const {
    return left->evaluate(x) * right->evaluate(x);
}


shared_ptr<Expression> Multiply::derivative() const {
    auto term1 = std::make_shared<Multiply>(left->derivative(), right);
    auto term2 = std::make_shared<Multiply>(left, right->derivative());
    return std::make_shared<Add>(term1, term2);
}

string Multiply::toString() const {
    return "(" + left->toString() + " * " + right->toString() + ")";
}


double Power::evaluate(double x) const {
    return pow(left->evaluate(x), right->evaluate(x));
}


shared_ptr<Expression> Power::derivative() const {
    // Tomamos el valor constante del exponente
    auto nConst = dynamic_pointer_cast<Constant>(right);
    double n = nConst ? nConst->evaluate(0) : 2.0;

    auto newExp = make_shared<Constant>(n - 1);
    auto powTerm = make_shared<Power>(left, newExp);
    auto multCoeff = make_shared<Multiply>(right, powTerm);

    return make_shared<Multiply>(multCoeff, left->derivative());
}

string Power::toString() const {
    return "(" + left->toString() + "^" + right->toString() + ")";
}

// --- Sin ---
double Sin::evaluate(double x) const {
    return sin(arg->evaluate(x));
}

// Regla de la cadena: sin(u)' = cos(u) * u'
shared_ptr<Expression> Sin::derivative() const {
    return make_shared<Multiply>(make_shared<Cos>(arg), arg->derivative());
}

string Sin::toString() const {
    return "sin(" + arg->toString() + ")";
}

// --- Cos ---
double Cos::evaluate(double x) const {
    return cos(arg->evaluate(x));
}

// Regla de la cadena: cos(u)' = -sin(u) * u'
shared_ptr<Expression> Cos::derivative() const {
    auto negOne = make_shared<Constant>(-1);
    auto negSin = make_shared<Multiply>(negOne, make_shared<Sin>(arg));
    return make_shared<Multiply>(negSin, arg->derivative());
}

string Cos::toString() const {
    return "cos(" + arg->toString() + ")";
}