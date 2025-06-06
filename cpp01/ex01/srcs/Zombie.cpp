#include "../Zombie.hpp"


Zombie::Zombie():
_name("Frederik")
{

}

Zombie::Zombie(std::string name):
_name(name)
{
    
}


Zombie::~Zombie(void)
{

}

void Zombie::set_name(std::string name){
    this->_name = name;
}

void Zombie::announce(){

    std::cout << this->_name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}
