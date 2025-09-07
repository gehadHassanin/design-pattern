#include <iostream>
#include "calculator.h"

NumExpression::NumExpression(int32_t num) : num_(num) {}

int NumExpression::interpret(Context& context) { return num_; }

AddExpression::AddExpression(Expression* left, Expression* right) 
    : left_(left), right_(right) {}

int AddExpression::interpret(Context& context) {
    return left_->interpret(context) + right_->interpret(context);
}

MulExpression::MulExpression(Expression* left, Expression* right)
    : left_(left), right_(right) {}

int MulExpression::interpret(Context& context) {
    return left_->interpret(context) * right_->interpret(context);
}

Interpreter::Interpreter(Context context) : context_(context) {}

Expression* Interpreter::buildExpressionTree_(const std::string& exp) {
    // Logic to parse expression and create expression tree
    MulExpression* mulExp = new MulExpression(new NumExpression(2), 
        new NumExpression(4));
    return new AddExpression(new NumExpression(1), mulExp);
}
int Interpreter::interpret(const std::string& exp) { 
    // 1- ASSUME PARSING INPUT
    Expression* expTree = Interpreter::buildExpressionTree_(exp);
    //delete expTree;
    return expTree->interpret(context_);
}