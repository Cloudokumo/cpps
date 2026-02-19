#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <string>
#include <stdint.h>

struct Data
{
    int         n;
    std::string s;
    float       f;
};

class Serializer
{
    private:
        Serializer();
        Serializer(const Serializer &s);
    public:
        static uintptr_t    serialize(Data* ptr);
        static Data*        deserialize(uintptr_t raw);
};

#endif