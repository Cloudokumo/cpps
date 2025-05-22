#include "Contact.hpp"


Contact::Contact(void){
    return;
}

Contact::~Contact(void){
    return;
}

void set_info(std:string msg)
{
    std::string dest;

    std::cout << msg;
    while(1)
    {
        std::getline(std::cin, dest);
        if (dest.empty())
            std::count << "missing field" << std::endl
        else
            break;
    }
    return(dest);
}
