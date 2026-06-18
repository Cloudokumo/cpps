#include "RPN.hpp"
 

RPN::RPN()
{}

RPN::RPN(const RPN &other) : _stack(other._stack) 
{}
 
RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
        _stack = other._stack;
    return *this;
}
 
RPN::~RPN()
{}
 
 
bool RPN::isOperator(char c) const
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}
 
bool RPN::applyOperator(char op)
{
    if (_stack.size() < 2)
    {
        std::cerr << "Error: not enough operands." << std::endl;
        return false;
    }
 
    long b = _stack.top(); _stack.pop();
    long a = _stack.top(); _stack.pop();
 
    switch (op)
    {
        case '+':
            _stack.push(a + b); 
            break;
        case '-': 
            _stack.push(a - b); 
            break;
        case '*': 
            _stack.push(a * b); 
            break;
        case '/':
            if (b == 0)
            {
                std::cerr << "Error: division by zero." << std::endl;
                return false;
            }
            _stack.push(a / b);
            break;
    }
    return true;
}
 
int RPN::evaluate(const std::string &expression)
{
    for (size_t i = 0; i < expression.size(); i++)
    {
        char c = expression[i];
 
        if (c == ' ')
            continue;
 
        if (c >= '0' && c <= '9')
        {
            _stack.push(c - '0');
        }
        else if (isOperator(c))
        {
            if (!applyOperator(c))
                return 1;
        }
        else
        {
            std::cerr << "Error: invalid token '" << c << "'." << std::endl;
            return 1;
        }
    }
 
    if (_stack.size() != 1)
    {
        std::cerr << "Error: invalid expression." << std::endl;
        return 1;
    }
 
    std::cout << _stack.top() << std::endl;
    return 0;
}
 