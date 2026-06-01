#include "MutantStack.hpp"

#include <iostream>

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    
    // empty check
    MutantStack<int> empty;
    if (empty.empty())
        std::cout << "empty: yes" << std::endl;
    else
        std::cout << "empty: no" << std::endl;
    // copy constructor
    MutantStack<int> copy(mstack);
    std::cout << "copy size: " << copy.size() << std::endl; // same as mstack

    // assignment operator
    MutantStack<int> assigned;
    assigned = mstack;
    std::cout << "assigned top: " << assigned.top() << std::endl; // 0

    // iterate over copy to confirm same content
    MutantStack<int>::iterator it2 = copy.begin();
    while (it2 != copy.end())
    {
        std::cout << *it2 << std::endl;
        ++it2;
    }

    return 0;
}