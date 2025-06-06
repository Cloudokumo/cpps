#include "Zombie.hpp"
Zombie* zombieHorde( int N, std::string name );

int main(){
    Zombie *aawa;
    int N;

    N = 5;
    aawa = zombieHorde(N, "robert");
    for (int i = 0; i < N; i++)
    {
        aawa[i].announce();
    }
    delete[] aawa;
}