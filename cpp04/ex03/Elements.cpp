#include "Elements.hpp"

Ice::Ice() : AMateria("ice")
{
    // std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(const Ice& other) : AMateria(other)
{
    // std::cout << "Ice copy constructor called" << std::endl;
    *this = other;
}

Ice& Ice::operator=(const Ice& other)
{
    if (this != &other)
        AMateria::operator=(other);
    // std::cout << "Ice assignment operator called" << std::endl;
    return *this;
}

Ice::~Ice()
{
    // std::cout << "Ice destructor called" << std::endl;
}

AMateria* Ice::clone() const
{
    return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Cure::Cure() : AMateria("cure")
{
    // std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other)
{
    // std::cout << "Cure copy constructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& other)
{
    if (this != &other)
        AMateria::operator=(other);
    // std::cout << "Cure assignment operator called" << std::endl;
    return *this;
}

Cure::~Cure()
{
    // std::cout << "Cure destructor called" << std::endl;
}

AMateria* Cure::clone() const
{
    return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

