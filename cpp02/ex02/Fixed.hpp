#pragma once 
#include <iostream>
#include <cmath>

class Fixed{
    private:
        int _val;
        static const int _bits = 8;
    public:
        Fixed();
        Fixed(const Fixed &other);
        Fixed(const int val);
        Fixed(const float val);
        ~Fixed();
        Fixed &operator=(const Fixed &other);
        Fixed &operator+(const Fixed &other) const;
        Fixed &operator-(const Fixed &other) const;
        Fixed &operator*(const Fixed &other) const;
        Fixed &operator/(const Fixed &other) const;
        int getRawBits(void) const;
        void setRawBits(int const array);
        float toFloat(void)const;
        int toInt(void) const;
};

std::ostream& operator<<(std::ostream& o, const Fixed& oui);