#pragma once
#include "ICharacter.hpp"

class Character : public ICharacter
{
private:
    std::string _name;
    AMateria* _inventory[4];
    static AMateria* _floor[100]; // Pour stocker les materia non équipées
    static int _floorCount;

public:
    Character();
    Character(const std::string& name);
    Character(const Character& other);
    Character& operator=(const Character& other);
    virtual ~Character();

    virtual std::string const & getName() const;
    virtual void equip(AMateria* m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter& target);

    static void clearFloor();
};