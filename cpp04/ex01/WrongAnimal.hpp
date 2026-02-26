#pragma once
#include <iostream>
#include <string>

class WrongAnimal
{
    protected:
        std::string type;
    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal &other);
        ~WrongAnimal();
        const WrongAnimal &operator=(const WrongAnimal &other);
        void makeSound() const;
        std::string getType()const;
};