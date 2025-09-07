#pragma once
#include <stdint.h> 

class Context {
 
};

// ABSTRACT CLASS => Expression
class Expression {
 public:
    virtual int interpret(Context& context) = 0;
};

// TERMINAL EXPRESSION 
class NumExpression : public Expression {
 public:
    NumExpression(int32_t num);
    int interpret(Context& context) override;
 private:
    int32_t num_;
};

// NON TERMINAL EXPRESSION 
class AddExpression : public Expression {
 public:
   AddExpression(Expression* left, Expression* right); 
   int interpret(Context& context) override;
 private:
    Expression* left_;
    Expression* right_;
};

// NON TERMINAL EXPRESSION
class MulExpression : public Expression {
 public:
   MulExpression(Expression* left, Expression* right); 
   int interpret(Context& context) override;
 private:
    Expression* left_;
    Expression* right_;
};

class Interpreter {
 public:
    Interpreter(Context context);
    int interpret(const std::string& exp);
    ~Interpreter() {};
 private:
    Context context_;
    Expression* buildExpressionTree_(const std::string& exp);
};