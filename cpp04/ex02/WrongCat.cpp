#include "WrongCat.hpp"

WrongCat::WrongCat() {
    type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
    *this = other;
}

WrongCat::~WrongCat() {
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
    if (this != &other) {
        WrongAnimal::operator=(other);
    }
    return *this;
}

void WrongCat::makeSound() const {
    std::cout << "WrongCat meows" << std::endl;
}
