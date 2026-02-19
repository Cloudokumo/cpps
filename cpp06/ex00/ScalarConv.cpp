#include "ScalarConv.hpp"
#include <iostream>
#include <cmath>
#include <climits>
#include <cfloat>

void ScalarConverter::convert(const std::string &literal)
{
    if (isSpecial(literal)) 
        printFromSpecial(literal);
    else if (isChar(literal))    
        printFromChar(literal[0]);
    else if (isInt(literal))     
        printFromInt(atoi(literal.c_str()));
    else if (isFloat(literal))   
        printFromFloat(static_cast<float>(atof(literal.c_str())));
    else if (isDouble(literal))  
        printFromDouble(atof(literal.c_str()));
    else
        std::cout << "Error: invalid literal" << std::endl;
}