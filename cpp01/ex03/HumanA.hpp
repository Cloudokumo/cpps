#pragma once
#include "Weapon.hpp"

class HumanA{
    private:
        std::string _name;
        Weapon _weapon;

    public:
        HumanA(void);
        ~HumanA(void);
        HumanA(Weapon weapon);
        void attack(void);
};