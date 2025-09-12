#include "Character.hpp"

AMateria* Character::_floor[100] = {NULL};
int Character::_floorCount = 0;

Character::Character() : _name("default")
{
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
    // std::cout << "Character default constructor called" << std::endl;
}

Character::Character(const std::string& name) : _name(name)
{
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
}

Character::Character(const Character& other) : _name(other._name)
{
    *this = other;
}   

Character& Character::operator=(const Character& other)
{
    if (this != &other)
    {
        _name = other._name;
        for (int i = 0; i < 4; i++)
        {
            if (_inventory[i])
                delete _inventory[i];
            if (other._inventory[i])
                _inventory[i] = other._inventory[i]->clone();
            else
                _inventory[i] = NULL;
        }
    }
    // std::cout << "Character assignment operator called" << std::endl;
    return *this;
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        if (_inventory[i])
            delete _inventory[i];
    }
    // std::cout << "Character destructor called" << std::endl;
}

std::string const & Character::getName() const
{
    return _name;
}

void Character::equip(AMateria* m)
{
    if (!m)
        return;
    for (int i = 0; i < 4; i++)
{
    if (_inventory[i] == m)
    {
        std::cout << _name << " already has this materia equipped." << std::endl;
        return;
    }
}
    for (int i = 0; i < 4; i++)
    {
        if (!_inventory[i])
        {
            _inventory[i] = m;
            std::cout << _name << " equipped " << m->getType() << " in slot " << i << std::endl;
            return;
        }
    }
    std::cout << _name << "'s inventory is full. Cannot equip " << m->getType() << std::endl;
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4 || !_inventory[idx])
    {
        std::cout << "Invalid index or empty slot. Cannot unequip." << std::endl;
        return;
    }
    if (_floorCount < 100)
    {
        _floor[_floorCount++] = _inventory[idx];
        std::cout << _name << " unequipped " << _inventory[idx]->getType() << " from slot " << idx << " to the floor." << std::endl;
    }
    else
    {
        delete _inventory[idx];
        std::cout << "Floor is full. " << _inventory[idx]->getType() << " is deleted." << std::endl;
    }
    _inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= 4 || !_inventory[idx])
    {
        std::cout << "Invalid index or empty slot. Cannot use." << std::endl;
        return;
    }
    _inventory[idx]->use(target);
}

void Character::clearFloor()
{
    for (int i = 0; i < _floorCount; i++)
    {
        delete _floor[i];
        _floor[i] = NULL;
    }
    _floorCount = 0;
    std::cout << "Floor has been cleaned." << std::endl;
}