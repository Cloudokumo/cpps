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

Fixed::Fixed(const int val):
_val(val << _bits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float val):
_val(roundf(val * (1 << _bits)))
{
	std::cout << "Float constructor called" << std::endl;
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
	std::cout << "getRawBits member function called" << std::endl;
    return (this->_val);
}

void Fixed::setRawBits(int const raw)
{
    this->_val = raw;
}

float Fixed::toFloat(void) const
{
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



Fixed Fixed::operator+(const Fixed& other) const 
{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const 
{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const 
{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const 
{
    return Fixed(this->toFloat() / other.toFloat());
}


Fixed& Fixed::operator++(void)
{
	this->_val++;
	return (*this);
}

Fixed& Fixed::operator--(void)
{
	this->_val--;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed	tmp = *this;
	++this->_val;
	return (tmp);
}

Fixed Fixed::operator--(int)
{
	Fixed	tmp = *this;
	--this->_val;
	return (tmp);
}

bool Fixed::operator==(const Fixed& other) const
{
	return (this->_val == other._val);
}

bool Fixed::operator<(const Fixed& other) const
{
	return (this->_val < other._val);
}

bool Fixed::operator>(const Fixed &other) const
{
	return (this->toFloat() > other.toFloat());
}

bool Fixed::operator<=(const Fixed& other) const
{
	return (this->_val <= other._val);
}

bool Fixed::operator>=(const Fixed& other) const
{
	return (this->_val >= other._val);
}

bool Fixed::operator!=(const Fixed& other) const
{
	return (this->_val != other._val);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a._val <= b._val)
		return (a);
	return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a._val >= b._val)
		return (a);
	return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a._val <= b._val)
		return (a);
	return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a._val >= b._val)
		return (a);
	return (b);
}
