#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    this->_guarding_gate = false;
    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    this->_guarding_gate = false;
    std::cout << "ScavTrap " << this->_name << " constructor called" << std::endl;
}


ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
    this->_guarding_gate = other._guarding_gate;
}


ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    std::cout << "ScavTrap assignment operator called" << std::endl;
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    this->_guarding_gate = other._guarding_gate;
    return *this;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap " << this->_name << " destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
     std::cout << this->_name << std::endl;
    if (this->_hitPoints == 0)
    {
        std::cout << "ScavTrap " << this->_name << " is dead and cannot attack" << std::endl;
        return;
    }
    if (this->_energyPoints == 0)
    {
        std::cout << "ScavTrap " << this->_name << " has no energy left to attack" << std::endl;
        return;
    }
    
    this->_energyPoints--;
    std::cout << "ScavTrap " << this->_name << " attacks " << target 
              << ", causing " << this->_attackDamage << " points of damage" << std::endl;
}

void ScavTrap::guardGate(void)
{
    if (this->_hitPoints == 0)
    {
        std::cout << "ScavTrap " << this->_name << " is dead and cannot guard the gate" << std::endl;
        return;
    }
    if (this->_guarding_gate == true)
    {
        std::cout << "ScavTrap" << this->_name << "is alredy guarding the gate" << std::endl;
        return ;
    }
    std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode" << std::endl;
    this->_guarding_gate = true;
}

void ScavTrap::printStats(void) const
{
    std::cout << "ScavTrap " << this->_name << " Stats =" << std::endl;
    std::cout << "Hit Points: " << this->_hitPoints << std::endl;
    std::cout << "Energy Points: " << this->_energyPoints << std::endl;
    std::cout << "Attack Damage: " << this->_attackDamage << std::endl;

}