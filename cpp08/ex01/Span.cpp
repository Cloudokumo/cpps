#include "Span.hpp"

Span::Span(unsigned int N) : _N(N) 
{
}

Span::Span(const Span &other) : _N(other._N), _vec(other._vec)
{
}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        _N = other._N;
        _vec = other._vec;
    }
    return *this;
}

Span::~Span() 
{
}

void Span::addNumber(int i)
{
    if (_vec.size() >= _N)
        throw std::runtime_error("Span is full");
    _vec.push_back(i);
}

int Span::shortestSpan()
{
    if (_vec.size() < 2)
        throw std::runtime_error("Not enough numbers to find a span");
    std::vector<int> sorted(_vec);
    std::sort(sorted.begin(), sorted.end());
    int shortest = sorted[1] - sorted[0];
    for (size_t i = 1; i < sorted.size(); i++)
    {
        shortest = std::min(shortest, sorted[i] - sorted[i - 1]);
    }
    return shortest;
}

int Span::longestSpan()
{
    if (_vec.size() < 2)
        throw std::runtime_error("Not enough numbers to find a span");
    int min = *std::min_element(_vec.begin(), _vec.end());
    int max = *std::max_element(_vec.begin(), _vec.end());
    return max - min;
}