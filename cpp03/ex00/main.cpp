#include "ClapTrap.hpp"

int main() {
    ClapTrap claptrap1("ClapTrap1");
    ClapTrap claptrap2("ClapTrap2");
    ClapTrap Clap1(claptrap1);

    claptrap1.attack("ClapTrap2");
    claptrap2.takeDamage(5);
    claptrap2.beRepaired(3);
    claptrap1.attack("ClapTrap2");
    claptrap2.takeDamage(10);
    claptrap2.beRepaired(5);
    claptrap1.attack("ClapTrap2");
    claptrap2.takeDamage(5);
    claptrap2.beRepaired(2);
    claptrap1.attack("ClapTrap2");
    claptrap1 = claptrap2;
    claptrap1.attack("ClapTrap2");
    claptrap2.takeDamage(5);

    return 0;
}