#pragma once

#include <algorithm>
#include <vector>

namespace AADS {
    template <typename In, typename T>
    bool in_range(In begin, In end, T element) {
        return std::find(begin, end, element) != end;
    }

    template <typename T>
    bool in_vector(const std::vector<T>& vector, T element) {
        return in_range(vector.begin(), vector.end(), element);
    }

    /** Returns an iterator half between two iterators. */
    template <typename In>
    In middle(In begin, In end) {
        return std::next(begin, std::distance(begin, end) / 2);
    }
}