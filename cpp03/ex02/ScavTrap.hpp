#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{

    private:
        bool _guarding_gate;
    public:
        ScavTrap(void);
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap &other);
        ScavTrap &operator=(const ScavTrap &other);
        ~ScavTrap(void);

        void attack(const std::string &target);
        void guardGate(void);
        void printStats(void) const;

};