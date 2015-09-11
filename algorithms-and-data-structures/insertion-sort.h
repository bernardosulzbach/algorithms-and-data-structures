#pragma once

#include <algorithm>

template <typename RandomAccessIterator>
void insertion_sort(RandomAccessIterator first, RandomAccessIterator last) {
    if (std::distance(first, last) < 2) {
        return;
    }
    for (auto i = std::next(first); i != last; i++) {
        // std::upper_bound(first, last, val)
        //    Returns an iterator pointing to the first element in the range [first, last)
        //    which compares greater than val or last if no such element exists.
        // std::rotate(first, n_first, last)
        //    Performs a left rotation on a range of elements.
        //    Specifically, std::rotate swaps the elements in the range [first, last)
        //    in such a way that the element n_first becomes the first element of the new
        //    range and n_first - 1 becomes the last element.
        std::rotate(std::upper_bound(first, i, *i), i, std::next(i));
    }
}