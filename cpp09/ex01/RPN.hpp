#pragma once

# include <iostream>
# include <stack>
# include <string>
 
class RPN
{
public:
    RPN();
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);
    ~RPN();
 
    int evaluate(const std::string &expression);
 
private:
    std::stack<long> _stack;
 
    bool isOperator(char c) const;
    bool applyOperator(char op);
};
