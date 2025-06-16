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

std::string const &Weapon::getType(void) const{
    return this->_type;
}
