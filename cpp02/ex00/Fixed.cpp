#include "Fixed.hpp"

Fixed::Fixed():
_val(0)
{  
}

Fixed::Fixed(const Fixed &other)
{
    this->_val = other._val;  
}

Fixed::~Fixed()
{ 
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