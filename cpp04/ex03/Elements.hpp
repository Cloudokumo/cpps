#include "AMateria.hpp"

class Ice : public AMateria
{
public:
    Ice();
    Ice(const Ice& other);
    Ice& operator=(const Ice& other);
    virtual ~Ice();

    virtual AMateria* clone() const;
    virtual void use(ICharacter& target);
};

class Cure : public AMateria
{
public:
    Cure();
    Cure(const Cure& other);
    Cure& operator=(const Cure& other);
    virtual ~Cure();

    virtual AMateria* clone() const;
    virtual void use(ICharacter& target);
};

 
