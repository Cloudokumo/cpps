#include "Fixed.hpp"

Fixed::Fixed():
_val(0)
{  
}

Fixed::Fixed(const Fixed &other)
{
    this->_val = other._val;  
}

Fixed::Fixed(const int val):
_val(val << _bits)
{

}

Fixed::Fixed(const float val):
_val(roundf(val * (1 << _bits)))
{
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

float Fixed::toFloat(void) const{
    return (static_cast<float>(this->_val) / (1 << Fixed::_bits));
}

int Fixed::toInt(void) const
{
    return (this->_val >> Fixed::_bits);
}

std::ostream& operator<<(std::ostream& o, const Fixed& oui)
{
    o << oui.toFloat();
    return (o);
}


Fixed &Fixed::operator+(const Fixed &other) const
{
    return(this->_val + other._val);
}


Fixed &Fixed::operator-(const Fixed &other) const
{
    return(this->_val - other._val);
}


Fixed &Fixed::operator*(const Fixed &other) const
{
    return(this->_val * other._val);
}

Fixed &Fixed::operator/(const Fixed &other) const
{
    return(this->_val / other._val);
}