#ifndef CONTACT_H
# define CONTACT_H

#include <string>
#include <iostream>

class Contact{
public:
    Contact();
    ~Contact();

    Contact(std::string first_name, std::string last_name, std::string nickname, std::string phone, std::string secret);
    int missing(Contact contact);

private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone;
    std::string secret;


};

#endif