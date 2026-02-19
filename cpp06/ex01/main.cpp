#include <iostream>
#include "Serializer.hpp"

int main()
{
    Data data;
    data.n = 42;
    data.s = "hello";
    data.f = 3.14f;

    std::cout << "Original pointer:     " << &data << std::endl;

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized value:     " << raw << std::endl;

    Data* result = Serializer::deserialize(raw);
    std::cout << "Deserialized pointer: " << result << std::endl;

    if (&data == result) 
    {
        std::cout << "Pointers match: YES" << std::endl;
    }   
     else  
    {
        std::cout << "Pointers match: NO" << std::endl;
    }
    std::cout << "n: " << result->n << std::endl;
    std::cout << "s: " << result->s << std::endl;
    std::cout << "f: " << result->f << std::endl;

    return 0;
}