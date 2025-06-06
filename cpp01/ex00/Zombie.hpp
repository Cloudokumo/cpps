#pragma once

#include <string>
#include <iostream>

class Zombie{
    private:
        const std::string _name;

    public:
    
        Zombie(void);
        Zombie(std::string name);
        ~Zombie(void);
        void announce(void);

};