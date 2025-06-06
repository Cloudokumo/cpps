#pragma once
#include "Weapon.hpp"

class HumanB{
    private:
        std::string _name;
        Weapon _weapon;
        
    public:
        HumanB(void);
        ~HumanB(void);
        void attack(void);
};
