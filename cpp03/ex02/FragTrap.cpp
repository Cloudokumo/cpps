#include "FragTrap.hpp"


FragTrap::FragTrap() : ClapTrap()
{
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "FragTrap " << this->_name << " constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << this->_name << " destructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    std::cout << "FragTrap assignment operator called" << std::endl;
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    return *this;
}

void FragTrap::attack(const std::string& target)
{
    if (this->_hitPoints == 0)
    {
        std::cout << "FragTrap " << this->_name << " is dead and cannot attack" << std::endl;
        return;
    }
    if (this->_energyPoints == 0)
    {
        std::cout << "FragTrap " << this->_name << " has no energy left to attack" << std::endl;
        return;
    }
    
    this->_energyPoints--;
    std::cout << "FragTrap " << this->_name << " attacks " << target 
              << ", causing " << this->_attackDamage << " points of damage" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->_name << " requests a high five" << std::endl;
}