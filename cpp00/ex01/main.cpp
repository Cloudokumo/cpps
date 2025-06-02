#include "includes/Phonebook.hpp"


int main() {
    std::string cmd;
    Phonebook pb;
    
    std::cout << "Welcome to the Phonebook" << std::endl;
    std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;
    
    while (true) 
    {
        std::cout << "Enter command: ";
        std::getline(std::cin, cmd);
        
        if (cmd == "ADD") {
            pb.add_contact();
        } else if (cmd == "SEARCH") {
            pb.search_contacts();
        } else if (cmd == "EXIT") {
            return 0;
        } else if (std::cin.eof() == true){
            std::cout << std::endl << "ded"  ;
            std::exit(0); 
        } 
        else {
            std::cout << "Invalid command. Please use ADD, SEARCH, or EXIT." << std::endl;
        }
    }
}