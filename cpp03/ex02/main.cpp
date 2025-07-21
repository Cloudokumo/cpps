#include "FragTrap.hpp"

int main()
{
    FragTrap defaultFrag;

    FragTrap frag1("Boomer");
    FragTrap frag2("Destroyer");

    FragTrap frag3(frag1);

    FragTrap frag4;
    frag4 = frag2;

    frag1.attack("Raider");
    frag1.attack("Nomad");
    frag1.attack("Goliath");

    frag1.takeDamage(40);
    frag1.takeDamage(35);

    frag1.beRepaired(20);
    frag1.beRepaired(15);

    frag1.highFivesGuys();
    frag2.highFivesGuys();
    defaultFrag.highFivesGuys();

    frag2.highFivesGuys();
    frag2.highFivesGuys();
    frag2.highFivesGuys();

    FragTrap energyTest("EnergyTester");
    for (int i = 0; i < 102; i++) {
        if (i == 99) std::cout << "Almost out of energy..." << std::endl;
        energyTest.attack("Target");
    }
 
    FragTrap deathTest("DeathTest");
    deathTest.takeDamage(100);
    deathTest.attack("Phantom");
    deathTest.beRepaired(50);
    deathTest.highFivesGuys();

    FragTrap combo("Combo");
    combo.attack("Enemy1");
    combo.highFivesGuys();
    combo.takeDamage(20);
    combo.beRepaired(10);
    combo.highFivesGuys();
    combo.attack("Enemy2");

    return 0;
}