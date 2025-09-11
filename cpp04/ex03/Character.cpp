#include "Character.hpp"

Character::Character() : _name("default")
{
    for (int i = 0; i < 4; ++i)
        _inventory[i] = NULL;
    // std::cout << "Character default constructor called" << std::endl;
}
