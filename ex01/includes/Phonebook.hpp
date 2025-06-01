#pragma once

#include "Contact.hpp"

class Phonebook {
    public:
        Phonebook(void);
        ~Phonebook(void);
    
        void add_contact(void);
        void search_contacts(void);
    
    private:
        Contact _contacts[8];
        int _contact_count;
        int _next_index;
};

