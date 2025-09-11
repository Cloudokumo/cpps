#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"


int main()
{
    Animal *animals[10];
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;//should not create a leak
    delete i;
    for (int idx = 0; idx < 10; idx++)
    {
        if (idx < 5)
            animals[idx] = new Dog();
        else
            animals[idx] = new Cat();
    }
    for (int idx = 0; idx < 10; idx++)
        animals[idx]->makeSound();
    for (int idx = 0; idx < 10; idx++)
        delete animals[idx];
    {
        std::cout << "\nDEEP COPY \n" << std::endl;
        Cat originalCat;
        originalCat.setIdea(0, "Eat");
        originalCat.setIdea(1, "Nap");
        std::cout << "Original Cat's ideas:" << std::endl;
        std::cout << "Idea 0: " << originalCat.getIdea(0);
        std::cout << "\nIdea 1: " << originalCat.getIdea(1) << std::endl;
        Cat copiedCat = originalCat; // Calls copy constructor
        std::cout << "Copied Cat's ideas after copy:" << std::endl;
        std::cout << "Idea 0: " << copiedCat.getIdea(0);
        std::cout << "\nIdea 1: " << copiedCat.getIdea(1) << std::endl;
        copiedCat.setIdea(0, "Climb the curtains");
        std::cout << "Original Cat's ideas after modifying copied Cat:" << std::endl;
        std::cout << "Idea 0: " << originalCat.getIdea(0) << std::endl;
        std::cout << "\nIdea 1: " << originalCat.getIdea(1) << std::endl;
        std::cout << "Copied Cat's ideas after modification:" << std::endl;
        std::cout << "Idea 0: " << copiedCat.getIdea(0);
        std::cout << "\nIdea 1: " << copiedCat.getIdea(1) << std::endl;
    }

    return 0;
}