#pragma once

#include <algorithm>
#include <iterator>
#include <vector>

#include "utils.h"

template <typename RandomAccessIterator>
void quick_sort(RandomAccessIterator first, RandomAccessIterator last) {
    if (std::distance(first, last) < 2) return;
    RandomAccessIterator pivot = AADS::middle(first, last);
    // Where the sorting happens.
    // std::nth_element is a partial sorting algorithm that rearranges elements in [first, last) such that:
    //    The element pointed at by nth is changed to whatever element would occur in that position if [first, last) was sorted.
    //    All of the elements before this new nth element are less than or equal to the elements after the new nth element.
    std::nth_element(first, pivot, last);
    quick_sort(first, pivot);
    quick_sort(pivot, last);
}
