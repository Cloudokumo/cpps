#pragma once

#include <string>
#include <iostream>

class Weapon{
    private:
        std::string _type;
    public:    
        std::string &getType(void);
        void setType(std::string type);
        Weapon(void);
        Weapon(std::string type);
        ~Weapon(void);
    
};