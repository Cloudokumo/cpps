#include "../includes/Contact.hpp"


Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

void Contact::set_info(void) {
    this->_first_name = get_info("First name: ");
    this->_last_name = get_info("Last name: ");
    this->_nickname = get_info("Nickname: ");
    this->_phone = get_info("Phone number: ");
    this->_secret = get_info("Darkest secret: ");
}

void Contact::setFirst_name(const std::string& name) {
    this->_first_name = name;
}

void Contact::setLast_name(const std::string& name) {
    this->_last_name = name;
}

void Contact::setNickname(const std::string& nickname) {
    this->_nickname = nickname;
}

void Contact::setPhone(const std::string& phone) {
    this->_phone = phone;
}

void Contact::setSecret(const std::string& secret) {
    this->_secret = secret;
}

std::string Contact::getFirst_name(void) const {
    return this->_first_name;
}

std::string Contact::getLast_name(void) const {
    return this->_last_name;
}

std::string Contact::getNickname(void) const {
    return this->_nickname;
}

std::string Contact::getPhone(void) const {
    return this->_phone;
}

std::string Contact::getSecret(void) const {
    return this->_secret;
}

bool Contact::isEmpty(void) const {
    return getFirst_name().empty() && getLast_name().empty() && getNickname().empty() && 
           getPhone().empty() && getSecret().empty();
}

std::string Contact::truncate(const std::string& str, size_t width) const {
    if (str.length() > width) {
        return str.substr(0, width - 1) + ".";
    }
    return str;
}

void Contact::display_summary(int index) const {
    std::cout << std::setw(10) << index << "|";
    std::cout << std::setw(10) << truncate(getFirst_name(), 10) << "|";
    std::cout << std::setw(10) << truncate(getLast_name(), 10) << "|";
    std::cout << std::setw(10) << truncate(getNickname(), 10) << std::endl;
}


void Contact::display_full(void) const {
    std::cout << "First name: " << getFirst_name() << std::endl;
    std::cout << "Last name: " << getLast_name() << std::endl;
    std::cout << "Nickname: " << getNickname() << std::endl;
    std::cout << "Phone number: " << getPhone() << std::endl;
    std::cout << "Darkest secret: " << getSecret() << std::endl;
}


std::string Contact::get_info(std::string msg)
{
    std::string dest;

    std::cout << msg;
    while(1)
    {
        std::getline(std::cin, dest);
        if (std::cin.eof() == true){
           std::cout << std::endl << "ded"  ;
           std::exit(0); 
        } 
        else if (dest.empty())
            std::cout << "missing field" << std::endl;
        else
            break;
    }
    return (dest);
}
