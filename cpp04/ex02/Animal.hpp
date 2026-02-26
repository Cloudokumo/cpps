#pragma once

#include <iostream>
#include <string>
#include "Brain.hpp"


class Animal
{
    protected:
        std::string type;
        Animal();
    public:
        Animal(const Animal &other);
        virtual ~Animal();
        const Animal &operator=(const Animal &other);
        virtual void makeSound() const;
        virtual std::string getType()const;

};
