#include "Phonebook.hpp"

Phonebook::Phonebook(void){
    this->_contact[1];
    return;
}

Phonebook::~Phonebook(void)
{
}


int Phonebook::set_contact(){
    Contact new_contact;

    new_contact.set_info();


    this->_contact = new_contact;
}