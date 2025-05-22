#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <string>
#include <iostream>

class Phonebook{
public:    
    Phonebook(void);
    ~Phonebook(void);
    
    Phonebook   set_contact(Phonebook);
    void   display_contact(Phonebook);
private:

    contact _contact[8];
};

