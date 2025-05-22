#ifndef CONTACT_H
# define CONTACT_H

class Contact{
public:
    Contact();
    ~Contact();

    contact(std::string first_name, std::string last_name, std::string nickname, std::string phone, std::string secret);
    int missing(contact contact);

private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone;
    std::string secret;


}