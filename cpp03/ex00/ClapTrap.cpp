#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "Constructor ClapTrap has been called " << std::endl;
}

ClapTrap::ClapTrap(std::string Name) : _name(Name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "Constructor ClapTrap has been called " << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "Destructor ClapTrap has been called " << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other){
    std::cout << "Copy constructor ClapTrap has been called " << std::endl;
    *this = other;
}


void ClapTrap::attack(const std::string& target) {
    if (this->_hitPoints <= 0 || this->_energyPoints <= 0) {
        std::cout << "ClapTrap " << this->_name << " cannot attack because it has no hit points or energy points left." << std::endl;
        return;
    }
    std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
    this->_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->_hitPoints <= 0) {
        std::cout << "ClapTrap " << this->_name << " is already destroyed and cannot take more damage." << std::endl;
        return;
    }
    this->_hitPoints -= amount;
    if (this->_hitPoints < 0) 
    {
        this->_hitPoints = 0;
    }
    std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage! Remaining hit points: " << this->_hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) 
{
    if (this->_hitPoints <= 0 || this->_energyPoints <= 0) 
    {
        std::cout << "ClapTrap " << this->_name << " cannot be repaired because it has no hit points or energy points left." << std::endl;
        return;
    }
    this->_hitPoints += amount;
    this->_energyPoints--;
    std::cout << "ClapTrap " << this->_name << " has been repaired by " << amount << " points! Current hit points: " << this->_hitPoints << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    std::cout << "ClapTrap assignment operator called!" << std::endl;
    if (this != &other) {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return *this;
}