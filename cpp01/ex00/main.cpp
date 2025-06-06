#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main(){
    
    Zombie zombie1("aaa");
    Zombie *aawa;

    zombie1.announce();
    randomChump("bobby");
    aawa = newZombie("robert");
    aawa->announce();
    delete aawa;
}