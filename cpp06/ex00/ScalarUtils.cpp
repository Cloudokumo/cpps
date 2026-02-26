#include "ScalarConv.hpp"
#include <iostream>
#include <climits>
#include <cmath>
#include <iomanip>

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
    size_t i = 0;
    if (s.length() == 0 || i == s.length())
        return false;
    if (s[i] == '+' || s[i] == '-')
        i++;
    while (i < s.length()) {
        if (!std::isdigit(s[i]))
            return false;
        i++;
    }
    return true;
}

bool isFloat(const std::string &s)
{
    
    if (s[s.length() - 1] == 'f' && s.find('.') != std::string::npos)
    {
        if (s.find_first_of('f') == s.find_last_of('f') && s.find_first_of('.') == s.find_last_of('.'))
            return true;
    }
    return false;
}

bool isDouble(const std::string &s)
{
    if (s.find_first_not_of("0123456789+-.") != std::string::npos)
        return (false);
    if (s.find('.') != std::string::npos && (s.find_first_of('.') == s.find_last_of('.')))
        return (true);
    return false;
}

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
    if (d > std::numeric_limits<float>::max() || d < -std::numeric_limits<float>::max())
    {
        std::cout << "float: impossible" << std::endl;
        return;
    }
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
}

void printDouble(double d)
{
    if (std::isinf(d) || std::isnan(d))
    {
        std::cout << "double: impossible" << std::endl;
        return;
    }
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void printFromChar(char c)
{
    std::cout << "FROM CHAR" << std::endl;
    double d = static_cast<double>(c);
    printChar(d);
    printInt(d);
    printFloat(d);
    printDouble(d);
}

void printFromInt(const std::string &s)
{
    std::cout << "FROM INT" << std::endl;
     long long val;
    char *end;
    errno = 0;
    val = strtoll(s.c_str(), &end, 10);
    
    if (val < 0 || val > 127)
        std::cout << "char: impossible" << std::endl;
    else if (val < 32 || val == 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(val) << "'" << std::endl;

    if (errno == ERANGE || val < INT_MIN || val > INT_MAX)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(val) << std::endl;

    double d = static_cast<double>(val);
    printFloat(d);
    printDouble(d);
}

void printFromFloat(double d)
{
    std::cout << "FROM FLOAT" << std::endl;
    printChar(d);
    printInt(d);
    printFloat(d);
    printDouble(d);
}

void printFromDouble(double d)
{
    std::cout << "FROM DOUBLE" << std::endl;
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