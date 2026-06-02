#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <stdexcept>

class Span
{
    private:
        unsigned int _N;
        std::vector<int> _vec;
    public:
        Span(unsigned int N);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();

        void addNumber(int i);

        long shortestSpan() const;
        long longestSpan()  const; 
        
        template <typename Iterator>
        void addRange(Iterator begin, Iterator end)
        {
            if (std::distance(begin, end) + _vec.size() > _N)
                throw std::runtime_error("Span is full");
            _vec.insert(_vec.end(), begin, end);
        }
};

