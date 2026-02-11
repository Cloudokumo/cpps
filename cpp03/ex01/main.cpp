#include "ScavTrap.hpp"


int main()
{

    // ScavTrap defaultScav;

    ScavTrap scav1("Guardian");
    // ScavTrap scav2("Sentinel");

    ScavTrap scav3(scav1);
    scav3.attack("e");
    // ScavTrap scav4;
    // scav4 = scav2;


   
    // // scav1.attack("Bandit");
    // // scav1.attack("Psycho");
    // // scav1.attack("Skag");

   
    // scav1.takeDamage(30);
    // scav1.takeDamage(25);

    
    // scav1.beRepaired(15);
    // scav1.beRepaired(10);


 
    // scav1.guardGate();
    // scav2.guardGate();
    // defaultScav.guardGate();

  
    // ScavTrap energyTest("EnergyTester");
    // for (int i = 0; i < 52; i++) {
    //     if (i == 49) std::cout << "Almost out of energy..." << std::endl;
    //     energyTest.attack("Target");
    // }

    ScavTrap deathTest("DeathTest");
    deathTest.takeDamage(100);
    deathTest.attack("Ghost");
    deathTest.beRepaired(50);
 
    return 0;
}
