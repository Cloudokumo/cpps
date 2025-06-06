#include <string>
#include <iostream>

int main()
{
    std::string string = "HI THIS IS BRAIN";
    std::string *stringPTR = &string;
    std::string &stringREF = string;


    std::cout << "addr string " << &string << std::endl;
    std::cout << "addr stringPTR " << stringPTR << std::endl;
    std::cout << "addr stringREF " << &stringREF << std::endl;

    std::cout << "value string :" << string << std::endl;
    std::cout << "value stringPTR :" << *stringPTR << std::endl;
    std::cout << "value stringREF :" << stringREF << std::endl;
}   
