#include "Fixed.hpp"

Fixed::Fixed():
_val(0)
{ 
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    this->_val = other._val;  
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl; 
}

Fixed &Fixed::operator=(const Fixed &other)
{
    if (this != &other)
    {
        this->_val = other._val;
    } 
    return (*this);
}


int Fixed::getRawBits(void) const
{
    return (this->_val);
}

void Fixed::setRawBits(int const raw)
{
    this->_val = raw;
}