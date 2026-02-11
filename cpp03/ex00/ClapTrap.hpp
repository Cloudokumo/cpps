#pragma once

#include <iostream>
#include <string>

class ClapTrap
{
private:
    std::string _name;
    int _hitPoints;
    int _energyPoints;
    int _attackDamage;
public:
    ClapTrap();
    ClapTrap(std::string Name);
    ~ClapTrap();
    ClapTrap(const ClapTrap &other);
    ClapTrap& operator=(const ClapTrap& other);
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};
