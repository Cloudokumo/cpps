#pragma once 
#include <iostream>

class Fixed{
    private:
        int _val;
        static const int _bits = 8;
    public:
        Fixed();
        Fixed(const Fixed &other);
        ~Fixed();
        Fixed &operator=(const Fixed &other);
        int getRawBits(void) const;
        void setRawBits(int const array);
};