#pragma once

# include <string>

class ScalarConverter 
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &src);
    public:
        static void convert(const std::string &literal);
};

bool isSpecial(const std::string &s);
bool isChar(const std::string &s);
bool isInt(const std::string &s);
bool isFloat(const std::string &s);
bool isDouble(const std::string &s);

void printChar(double d);
void printInt(double d);
void printFloat(double d);
void printDouble(double d);

void printFromChar(char c);
void printFromInt(int n);
void printFromFloat(float f);
void printFromDouble(double d);
void printFromSpecial(const std::string &s);