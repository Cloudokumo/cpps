#include "ScalarConv.hpp"
#include <iostream>
#include <cmath>
#include <climits>
#include <cfloat>

void ScalarConverter::convert(const std::string &literal)
{
    if ((literal.length() > 1 && literal[literal.length() -1] =='.') || (literal.length() > 1 && literal[0] == '.'))
    {
        std::cout << "Error: invalid literal" << std::endl;
        return;
    }
    if (isSpecial(literal)) 
        printFromSpecial(literal);
    else if (isChar(literal))    
        printFromChar(literal[0]);
    else if (isInt(literal))
        printFromInt(literal);
    else if (isFloat(literal))   
        printFromFloat(atof(literal.c_str()));
    else if (isDouble(literal))  
        printFromDouble(atof(literal.c_str()));
    else
        std::cout << "Error: invalid literal" << std::endl;
}