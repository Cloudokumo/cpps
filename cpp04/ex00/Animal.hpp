#pragma once

#include <iostream>
#include <string>

class Animal
{
    protected:
        std::string type;
    public:
        Animal();
        Animal(const Animal &other);
        virtual ~Animal();
        const Animal &operator=(const Animal &other);
        virtual void makeSound() const;
        virtual std::string getType()const;
};
