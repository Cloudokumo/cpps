#pragma once
 
#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <ctime>
#include <climits>
#include <iomanip>
 
class PmergeMe
{
    private:
        std::vector<int> _vec;
        std::deque<int>  _deq;
 
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();
 
        static size_t jacobsthal(size_t n);
 
        void parseArgs(int argc, char **argv);
 
        std::vector<int> sortVec(std::vector<int> v);
        std::deque<int>  sortDeq(std::deque<int> d);
 
        const std::vector<int> &getVec() const;
        const std::deque<int>  &getDeq() const;
};
 