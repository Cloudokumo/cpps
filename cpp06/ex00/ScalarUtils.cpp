#include "ScalarConv.hpp"
#include <iostream>
#include <climits>
#include <cmath>

bool isSpecial(const std::string &s)
{
    return (s == "nan" || s == "nanf" || s == "+inf" || s == "-inf" || s == "+inff" || s == "-inff");
}

bool isChar(const std::string &s)
{
    return (s.length() == 1 && !std::isdigit(s[0]));
}

bool isInt(const std::string &s)
{
    int i = 0;
    if (s[i] == '+' || s[i] == '-')
        i++;
    if (s.length() == 0 || i == (int)s.length())
        return false;
    while (i < (int)s.length()) {
        if (!std::isdigit(s[i]))
            return false;
        i++;
    }
    return true;
}

bool isFloat(const std::string &s)
{
    return (s[s.length() - 1] == 'f' && s.find('.') != std::string::npos);
}

bool isDouble(const std::string &s)
{
    return (s.find('.') != std::string::npos);
}

// ─── Print helpers ─────────────────────────────────────────────────────────────

void printChar(double d)
{
    if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127)
        std::cout << "char: impossible" << std::endl;
    else if (d < 32 || d == 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
}

void printInt(double d)
{
    if (std::isnan(d) || std::isinf(d) || d < INT_MIN || d > INT_MAX)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(d) << std::endl;
}

void printFloat(double d)
{
    if (std::isnan(d))
    {
        std::cout << "float: nanf" << std::endl;
        return;
    }
    if (std::isinf(d))
    {
        std::cout << "float: " << (std::signbit(d) ? "-inff" : "+inff") << std::endl;
        return;
    }
    float f = static_cast<float>(d);
    std::cout << "float: " << f;
    if (f == static_cast<float>(static_cast<long long>(f)) && f >= -1e6f && f <= 1e6f)
        std::cout << ".0";
    std::cout << "f" << std::endl;
}

void printDouble(double d)
{
    if (std::isnan(d))
    {
        std::cout << "double: nan" << std::endl;
        return;
    }
    if (std::isinf(d))
    {
        std::cout << "double: " << (std::signbit(d) ? "-inf" : "+inf") << std::endl;
        return;
    }
    std::cout << "double: " << d;
    if (d == static_cast<double>(static_cast<long long>(d)) && d >= -1e15 && d <= 1e15)
        std::cout << ".0";
    std::cout << std::endl;
}

// ─── Print from type ───────────────────────────────────────────────────────────

void printFromChar(char c)
{
    double d = static_cast<double>(c);
    printChar(d);
    printInt(d);
    printFloat(d);
    printDouble(d);
}

void printFromInt(int n)
{
    double d = static_cast<double>(n);
    printChar(d);
    printInt(d);
    printFloat(d);
    printDouble(d);
}

void printFromFloat(float f)
{
    double d = static_cast<double>(f);
    printChar(d);
    printInt(d);
    printFloat(d);
    printDouble(d);
}

void printFromDouble(double d)
{
    printChar(d);
    printInt(d);
    printFloat(d);
    printDouble(d);
}

void printFromSpecial(const std::string &s)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    if (s == "nan" || s == "nanf")
    {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else if (s == "+inf" || s == "+inff")
    {
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
    else
    {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
}