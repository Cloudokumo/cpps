#pragma once

#include <string>
#include <iostream>

class Zombie{
    private:
        std::string _name;

    public:
    
        Zombie(void);
        Zombie(std::string name);
        ~Zombie(void);
        std::string get_name();
        void set_name(std::string name);
        void announce(void);

};