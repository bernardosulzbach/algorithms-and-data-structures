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
    template <typename RandomAccessIterator>
    /** Returns an iterator pointing to an element E such that E is bigger than or equal to its predecessor and its successor. */
    RandomAccessIterator peak(RandomAccessIterator begin, RandomAccessIterator end) {
        auto distance = std::distance(begin, end);
        if (distance == 0 || distance == 1) return begin;
        else {
            if (begin[distance / 2] < begin[distance / 2 - 1]) {
                return peak(begin, begin + distance / 2);
            }
            else if ((begin + distance / 2 + 1 != end) && begin[distance / 2] < begin[distance / 2 + 1]) {
                return peak(begin + distance / 2 + 1, end);
            }
            else {
                return begin + distance / 2;
            }
        }
    }
}