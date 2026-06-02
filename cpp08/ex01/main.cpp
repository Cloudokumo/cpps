#include "Span.hpp"

int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    try {
        sp.addNumber(99);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl; // Span is full
    }

    // test when not enough numbers
    try {
        Span sp2(5);
        sp2.addNumber(1);
        sp2.shortestSpan();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl; // Not enough numbers
    }

    // test addRange with a big range
    Span sp3(10000);
    std::vector<int> bigVec;
    for (int i = 0; i < 10000; i++)
        bigVec.push_back(i);

    sp3.addRange(bigVec.begin(), bigVec.end());
    std::cout << sp3.shortestSpan() << std::endl; // 1
    std::cout << sp3.longestSpan() << std::endl;  // 9999

    Span big(2);
    big.addNumber(-2147483648);
    big.addNumber(2147483647);
    std::cout<< big.longestSpan() <<std::endl;

    return 0;
}