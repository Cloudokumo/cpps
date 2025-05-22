#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"

class Phonebook{
public:    
    Phonebook(void);
    ~Phonebook(void);
    
    Phonebook   set_contact(Phonebook);
    void   display_contact(Phonebook);
private:

    Contact _contact[8];
};

#endif