#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        _materia[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
    for (int i = 0; i < 4; i++)
    {
        if (other._materia[i])
            _materia[i] = other._materia[i]->clone();
        else
            _materia[i] = NULL;
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            delete _materia[i];
            if (other._materia[i])
                _materia[i] = other._materia[i]->clone();
            else
                _materia[i] = NULL;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
        delete _materia[i];
}
void MateriaSource::learnMateria(AMateria* materia)
{
    if (!materia)
        return;
    for (int i = 0; i < 4; i++)
    {
        if (!_materia[i])
        {
            _materia[i] = materia;
            return;
        }
    }
    std::cout << "MateriaSource is full, cannot learn more materia." << std::endl;
    delete materia;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (_materia[i] && _materia[i]->getType() == type)
            return _materia[i]->clone();
    }
    std::cout << "Materia of type " << type << " not found." << std::endl;
    return NULL;
}