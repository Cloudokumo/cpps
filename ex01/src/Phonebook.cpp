#include "Phonebook.hpp"

Phonebook::Phonebook(void){
    this->_contact[1];
    return;
}

Phonebook::~Phonebook(void){
    return;
}


Phonebook Phonebook::set_contact(void){
    contact new_contact(set_info("First name:"), set_info("Last name:"),
    set_info("Nickname:"),set_info("Phone number:"),
    set_info("Darkest secret:"));

    pb._contacts[i] = new_contact;
    i++;
}