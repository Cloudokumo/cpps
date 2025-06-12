#include "../Weapon.hpp"

Weapon::Weapon()
{
}

Weapon::Weapon(std::string type):_type(type)
{
}

Weapon::~Weapon()
{
}


void Weapon::setType(std::string weapon)
{
    this->_type = weapon;
}

std::string &Weapon::getType(void){
    return this->_type;
}
