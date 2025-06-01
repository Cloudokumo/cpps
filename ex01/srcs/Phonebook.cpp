#include "../includes/Phonebook.hpp"

Phonebook::Phonebook(void) {
    this->_contact_count = 0;
    this->_next_index = 0;
}
Phonebook::~Phonebook(void)
{
}

void Phonebook::add_contact(void) {
    _contacts[_next_index].set_info();
    
    if (std::cin.eof() == true)
        {
            std::cout << "ded" << std::endl ;
            std::exit(0); 
        } 
    if (_contact_count < 8) {
        _contact_count++;
    }
    
    _next_index = (_next_index + 1) % 8;
    std::cout << "Contact added successfully" << std::endl;
}

void Phonebook::search_contacts(void) {
    if (_contact_count == 0) {
        std::cout << "No contacts available." << std::endl;
        return;
    }
    
    std::cout << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First Name" << "|";
    std::cout << std::setw(10) << "Last Name" << "|";
    std::cout << std::setw(10) << "Nickname" << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    for (int i = 0; i < _contact_count; i++) {
        if (!_contacts[i].isEmpty()) {
            _contacts[i].display_summary(i);
        }
    }

    std::cout << "Enter index to view full contact info: ";
    std::string input;
    std::getline(std::cin, input);
    
    if (input.length() == 1 && input[0] >= '0' && input[0] <= '7') {
        int index = input[0] - '0';
        if (index < _contact_count && !_contacts[index].isEmpty()) {
            std::cout << std::endl;
            _contacts[index].display_full();
        } else {
            std::cout << "No contact at index " << index << std::endl;
        }
    } 
    else if (std::cin.eof() == true) 
    {
        std::cout << std::endl << "ded";
        std::exit(0); 
    } 
    else{
        std::cout << "Please enter a single digit (0-7)." << std::endl;
    }
}