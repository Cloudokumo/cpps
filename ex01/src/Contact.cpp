#include "Contact.hpp"


Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

void Contact::set_info(contact contact)
{
    
}

void Contact::setFirst_name(void);
{
    this->_first_name = get_info("first name :");
}

void Contact::setlast_name(void);
{
    this->_last_name = get_info("last name :");
}

void Contact::setnickname(void);
{
    this->_nickname= get_info("nickname :");
}


void Contact::setphone(void);
{
    this->_phone = get_info("phone :");
}

void Contact::setsecret(void);
{
    this->_secret = get_info("secret :");
}

std::string Contact::get_info(std::string msg)
{
    std::string dest;

    std::cout << msg;
    while(1)
    {
        std::getline(std::cin, dest);
        if (dest.empty())
            std::cout << "missing field" << std::endl;
        else
            break;
    }
    return (dest);
}
