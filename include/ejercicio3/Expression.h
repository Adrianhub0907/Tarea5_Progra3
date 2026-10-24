#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <memory>
#include <string>

class Expression {
public:
    virtual ~Expression() = default;
    virtual double evaluate(double x) const = 0;
    virtual std::shared_ptr<Expression> derivative() const = 0;
    virtual std::string toString() const = 0;
};

#endif