#include <iostream>
#include <string>
#include "Array.hpp"

int main( void ) 
{
    Array<int> ints(5);
    for (unsigned int i = 0; i < ints.size(); i++)
        ints[i] = i * 10;

    std::cout << "ints: ";

    for (unsigned int i = 0; i < ints.size(); i++)
        std::cout << ints[i] << " ";

    std::cout << std::endl;
    Array<int> copy(ints);
    copy[0] = 999;

    std::cout << "ints[0] after modifying copy: " << ints[0] << std::endl;
    std::cout << "copy[0]: " << copy[0] << std::endl;

    Array<std::string> strs(3);

    strs[0] = "hello";
    strs[1] = "world";
    strs[2] = "foo";

    std::cout << "strs: ";
    for (unsigned int i = 0; i < strs.size(); i++)
        std::cout << strs[i] << " ";
        
    std::cout << std::endl;
    Array<int> empty;

    std::cout << "empty size: " << empty.size() << std::endl;

    try 
    {
        std::cout << ints[99] << std::endl;
    } 
    catch (std::exception &e) 
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
