#include "../Zombie.hpp"


Zombie* zombieHorde( int N, std::string name )
{
    Zombie *Zombies;
    Zombies = new Zombie[N];
    for (int i = 0; i < N; i++)
    {
        Zombies[i].set_name(name);
    }
    return (Zombies); 
}
