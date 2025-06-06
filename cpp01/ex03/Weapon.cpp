#include "Weapon.hpp"

Weapon::Weapon()

{
}

Weapon::~Weapon()
{
}


void Weapon::setType(std::string weapon)
{
    this->_type = weapon;
}

std::string Weapon::getType(void){
    return this->_type;
}
