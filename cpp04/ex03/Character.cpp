#include "Character.hpp"


Character::Character() : _name("default"), _floorCount(0)
{
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
    for (int i = 0; i < 100; i++)
		_floor[i] = NULL;
    // std::cout << "Character default constructor called" << std::endl;
}

Character::Character(const std::string& name) : _name(name), _floorCount(0)
{
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
    for (int i = 0; i < 100; i++)
		_floor[i] = NULL;
}

Character::Character(const Character& other) : _name(other._name)
{
    *this = other;
}   

Character& Character::operator=(const Character& other)
{
    if (this != &other)
    {
        this->_name = other._name;
        for (int i = 0; i < 4; i++)
        {
            if (this->_inventory[i])
                delete _inventory[i];
            if (other._inventory[i])
                this->_inventory[i] = other._inventory[i]->clone();
            else
                this->_inventory[i] = NULL;
        }
        for (int i = 0; i < 100; ++i)
		{
			if (this->_floor[i])
			{
				delete this->_floor[i];
				this->_floor[i] = NULL;
			}
			if (other._floor[i])
				this->_floor[i] = other._floor[i]->clone();
			else
				this->_floor[i] = NULL;
		}
    }
    this->_floorCount = other._floorCount;
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
    int i = 0;
    while (i < _floorCount)
    {
        delete this->_floor[i];
        _floor[i] = NULL;
        i++;
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
    {
        std::cout << "Can't learn a Null pointer"<< std::endl;
		return ;
    }
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
			for (int j = 0; j < 100 ; j++)
			{
				if (m == this->_floor[j])
					this->_floor[j] = NULL;
			}
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
        std::cout << "current floor index" << _floorCount << std::endl;
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