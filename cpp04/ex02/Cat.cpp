#include "Cat.hpp"

Cat::Cat() {
    std::cout << "Cat constructor called" << std::endl;
    type = "Cat";
    _brain = new Brain();
}

Cat::Cat(const Cat &other) : Animal(other) {
    std::cout << "Cat copy constructor called" << std::endl;
    _brain = new Brain(*other._brain);
    *this = other;
}

Cat::~Cat() {
    delete _brain;
    std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
    std::cout << "Cat assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        if (_brain)
            delete _brain;
        _brain = new Brain(*other._brain);
    }
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Cat meows" << std::endl;
}

void Cat::setIdea(int index, const std::string &idea) {
    _brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const {
    return _brain->getIdea(index);
}