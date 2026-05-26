#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int main()
{
    // --- vector ---
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(42);

    // found
    try { std::cout << "vec find 42: " << easyfind(vec, 42) << std::endl; }
    catch (std::exception &e) { std::cout << "vec 42: " << e.what() << std::endl; }

    // not found
    try { std::cout << "vec find 99: " << easyfind(vec, 99) << std::endl; }
    catch (std::exception &e) { std::cout << "vec 99: " << e.what() << std::endl; }

    // --- list ---
    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);

    try { std::cout << "list find 20: " << easyfind(lst, 20) << std::endl; }
    catch (std::exception &e) { std::cout << "list 20: " << e.what() << std::endl; }

    try { std::cout << "list find 5: " << easyfind(lst, 5) << std::endl; }
    catch (std::exception &e) { std::cout << "list 5: " << e.what() << std::endl; }

    // --- deque ---
    std::deque<int> deq;
    deq.push_back(7);
    deq.push_back(8);
    deq.push_back(9);

    try { std::cout << "deque find 7: " << easyfind(deq, 7) << std::endl; }
    catch (std::exception &e) { std::cout << "deque 7: " << e.what() << std::endl; }

    try { std::cout << "deque find 0: " << easyfind(deq, 0) << std::endl; }
    catch (std::exception &e) { std::cout << "deque 0: " << e.what() << std::endl; }

    return 0;
}