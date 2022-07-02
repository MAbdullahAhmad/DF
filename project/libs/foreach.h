#ifndef FOREACH_H
#define FOREACH_H

#include "iostream"

using namespace std;

template<class InputIt, class UnaryFunction>
constexpr UnaryFunction for_each(InputIt first, InputIt last, UnaryFunction f)
{
    for (; first != last; ++first) {
        f(*first);
    }
    return f;
}

#endif