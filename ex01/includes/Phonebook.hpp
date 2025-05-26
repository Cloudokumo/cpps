#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"

class Phonebook{
    public:    
        Phonebook(void);
        ~Phonebook(void);
        
        int     set_contact();
        void     display_contact();
    private:
        Contact _contact[8];
};

#endif