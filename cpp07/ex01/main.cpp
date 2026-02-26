#include <iostream>
#include <string>
#include "iter.hpp"

void printInt(int const &x) 
{
    std::cout << x << " ";
}

void printStr(std::string const &x) 
{
    std::cout << x << " ";
}

void increment(int &x) 
{
    x++;
}

int main( void ) 
{
    int ints[] = {1, 2, 3, 4, 5};

    std::cout << "before: ";
    ::iter(ints, 5, printInt);
    std::cout << std::endl;

    ::iter(ints, 5, increment);

    std::cout << "after:  ";
    ::iter(ints, 5, printInt);
    std::cout << std::endl;

    std::string strs[] = {"hello", "world", "foo"};
    std::cout << "strs:   ";
    ::iter(strs, 3, printStr);
    std::cout << std::endl;

    return 0;
}
