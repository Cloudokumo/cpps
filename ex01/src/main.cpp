#include "Contact.hpp"
#include "Phonebook.hpp"

int main()
{
    std::string cmd;
    Phonebook pb;

    while(1)
    {
        std::getline(std::cin, cmd);
        if (cmd == "ADD")
            pb.set_contact();
        else if (cmd == "SEARCH")
            pb.display_contacts();
        else if (cmd == "EXIT")
            return (0);
        else  
            std::cout << "Invalid command. Please use ADD, SEARCH, or EXIT." << std::endl;
    }
}