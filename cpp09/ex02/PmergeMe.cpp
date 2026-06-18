#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(const PmergeMe &o) : _vec(o._vec), _deq(o._deq)
{}

PmergeMe &PmergeMe::operator=(const PmergeMe &o)
{
    if (this != &o)
    {
        _vec = o._vec;
        _deq = o._deq;
    }
    return *this;
}

PmergeMe::~PmergeMe()
{}

const std::vector<int> &PmergeMe::getVec() const
{
    return _vec;
}

const std::deque<int> &PmergeMe::getDeq() const
{
    return _deq;
}

void PmergeMe::parseArgs(int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
    {
        std::string s(argv[i]);
        for (size_t j = 0; j < s.size(); j++)
            if (s[j] < '0' || s[j] > '9')
                throw std::runtime_error("Error");
        long v = std::atol(s.c_str());
        if (v < 0 || v > INT_MAX)
            throw std::runtime_error("Error");
        _vec.push_back((int)v);
        _deq.push_back((int)v);
    }
    if (_vec.empty())
        throw std::runtime_error("Error");
}

size_t PmergeMe::jacobsthal(size_t n)
{
    size_t a = 0, b = 1;
    for (size_t i = 2; i <= n; i++)
    {
        size_t tmp = b + 2 * a;
        a = b;
        b = tmp;
    }
    if (n == 0)
        return 0;
    return b;
}

typedef std::pair<int, int> Pair;

static std::vector<Pair> sortPairsVec(std::vector<Pair> v)
{
    if (v.size() <= 1)
        return v;

    std::vector<Pair> big, small;
    for (size_t i = 0; i + 1 < v.size(); i += 2)
    {
        if (v[i].first >= v[i+1].first)
        {
            big.push_back(v[i]);
            small.push_back(v[i+1]);
        }
        else
        {
            big.push_back(v[i+1]);
            small.push_back(v[i]);
        }
    }
    bool odd = v.size() % 2;
    Pair straggler;
    if (odd)
        straggler = v.back();
    else
        straggler = Pair(0, 0);

    big = sortPairsVec(big);

    std::vector<Pair> chain(big);

    std::vector<Pair> pend(small.begin(), small.end());
    if (odd)
        pend.push_back(straggler);

    std::vector<bool> ins(pend.size(), false);
    size_t k = 2;
    while (true)
    {
        size_t jk = PmergeMe::jacobsthal(k);
        size_t jk1 = PmergeMe::jacobsthal(k - 1);
        if (jk1 >= pend.size())
            break;
        size_t hi;
        if (jk >= pend.size())
            hi = pend.size() - 1;
        else
            hi = jk - 1;
        for (size_t idx = hi + 1; idx > jk1; idx--)
        {
            size_t i = idx - 1;
            if (!ins[i])
            {
                std::vector<Pair>::iterator pos = chain.begin();
                while (pos != chain.end() && pos->first < pend[i].first)
                    ++pos;
                chain.insert(pos, pend[i]);
                ins[i] = true;
            }
        }
        k++;
    }
    for (size_t i = 0; i < pend.size(); i++)
    {
        if (!ins[i])
        {
            std::vector<Pair>::iterator pos = chain.begin();
            while (pos != chain.end() && pos->first < pend[i].first)
                ++pos;
            chain.insert(pos, pend[i]);
        }
    }
    return chain;
}

std::vector<int> PmergeMe::sortVec(std::vector<int> v)
{
    if (v.size() <= 1)
        return v;

    bool odd = v.size() % 2;
    int straggler;
    if (odd)
        straggler = v.back();
    else
        straggler = 0;

    std::vector<Pair> pairs;
    for (size_t i = 0; i + 1 < v.size(); i += 2)
    {
        if (v[i] >= v[i+1])
            pairs.push_back(Pair(v[i], v[i+1]));
        else
            pairs.push_back(Pair(v[i+1], v[i]));
    }

    pairs = sortPairsVec(pairs);

    std::vector<int> chain;
    chain.push_back(pairs[0].second);
    for (size_t i = 0; i < pairs.size(); i++)
        chain.push_back(pairs[i].first);

    std::vector<int> pend;
    for (size_t i = 1; i < pairs.size(); i++)
        pend.push_back(pairs[i].second);
    if (odd)
        pend.push_back(straggler);

    std::vector<bool> ins(pend.size(), false);
    size_t k = 2;
    while (true)
    {
        size_t jk = jacobsthal(k);
        size_t jk1 = jacobsthal(k - 1);
        if (jk1 >= pend.size())
            break;
        size_t hi;
        if (jk >= pend.size())
            hi = pend.size() - 1;
        else
            hi = jk - 1;
        for (size_t idx = hi + 1; idx > jk1; idx--)
        {
            size_t i = idx - 1;
            if (!ins[i])
            {
                chain.insert(std::lower_bound(chain.begin(), chain.end(), pend[i]), pend[i]);
                ins[i] = true;
            }
        }
        k++;
    }
    for (size_t i = 0; i < pend.size(); i++)
    {
        if (!ins[i])
            chain.insert(std::lower_bound(chain.begin(), chain.end(), pend[i]), pend[i]);
    }
    return chain;
}

typedef std::pair<int, int> DPair;

static std::deque<DPair> sortPairsDeq(std::deque<DPair> d)
{
    if (d.size() <= 1)
        return d;

    std::deque<DPair> big, small;
    for (size_t i = 0; i + 1 < d.size(); i += 2)
    {
        if (d[i].first >= d[i+1].first)
        {
            big.push_back(d[i]);
            small.push_back(d[i+1]);
        }
        else
        {
            big.push_back(d[i+1]);
            small.push_back(d[i]);
        }
    }
    bool odd = d.size() % 2;
    DPair straggler;
    if (odd)
        straggler = d.back();
    else
        straggler = DPair(0, 0);

    big = sortPairsDeq(big);

    std::deque<DPair> chain(big);

    std::deque<DPair> pend(small.begin(), small.end());
    if (odd)
        pend.push_back(straggler);

    std::vector<bool> ins(pend.size(), false);
    size_t k = 2;
    while (true)
    {
        size_t jk = PmergeMe::jacobsthal(k);
        size_t jk1 = PmergeMe::jacobsthal(k - 1);
        if (jk1 >= pend.size())
            break;
        size_t hi;
        if (jk >= pend.size())
            hi = pend.size() - 1;
        else
            hi = jk - 1;
        for (size_t idx = hi + 1; idx > jk1; idx--)
        {
            size_t i = idx - 1;
            if (!ins[i])
            {
                std::deque<DPair>::iterator pos = chain.begin();
                while (pos != chain.end() && pos->first < pend[i].first)
                    ++pos;
                chain.insert(pos, pend[i]);
                ins[i] = true;
            }
        }
        k++;
    }
    for (size_t i = 0; i < pend.size(); i++)
    {
        if (!ins[i])
        {
            std::deque<DPair>::iterator pos = chain.begin();
            while (pos != chain.end() && pos->first < pend[i].first)
                ++pos;
            chain.insert(pos, pend[i]);
        }
    }
    return chain;
}

std::deque<int> PmergeMe::sortDeq(std::deque<int> d)
{
    if (d.size() <= 1)
        return d;

    bool odd = d.size() % 2;
    int straggler;
    if (odd)
        straggler = d.back();
    else
        straggler = 0;

    std::deque<DPair> pairs;
    for (size_t i = 0; i + 1 < d.size(); i += 2)
    {
        if (d[i] >= d[i+1])
            pairs.push_back(DPair(d[i], d[i+1]));
        else
            pairs.push_back(DPair(d[i+1], d[i]));
    }

    pairs = sortPairsDeq(pairs);

    std::deque<int> chain;
    chain.push_back(pairs[0].second);
    for (size_t i = 0; i < pairs.size(); i++)
        chain.push_back(pairs[i].first);

    std::deque<int> pend;
    for (size_t i = 1; i < pairs.size(); i++)
        pend.push_back(pairs[i].second);
    if (odd)
        pend.push_back(straggler);

    std::vector<bool> ins(pend.size(), false);
    size_t k = 2;
    while (true)
    {
        size_t jk = jacobsthal(k);
        size_t jk1 = jacobsthal(k - 1);
        if (jk1 >= pend.size())
            break;
        size_t hi;
        if (jk >= pend.size())
            hi = pend.size() - 1;
        else
            hi = jk - 1;
        for (size_t idx = hi + 1; idx > jk1; idx--)
        {
            size_t i = idx - 1;
            if (!ins[i])
            {
                chain.insert(std::lower_bound(chain.begin(), chain.end(), pend[i]), pend[i]);
                ins[i] = true;
            }
        }
        k++;
    }
    for (size_t i = 0; i < pend.size(); i++)
    {
        if (!ins[i])
            chain.insert(std::lower_bound(chain.begin(), chain.end(), pend[i]), pend[i]);
    }
    return chain;
}