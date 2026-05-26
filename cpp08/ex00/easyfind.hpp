#pragma once

template <typename T>
int easyfind(T &l, int i)
{
    typename T::iterator it = std::find(l.begin(), l.end(), i);
    if (it == l.end())
        throw std::runtime_error("not found i");
    return (*it);
};