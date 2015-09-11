#pragma once

#include <algorithm>
#include <iterator>
#include <vector>

#include "utils.h"

template <typename RandomAccessIterator>
void merge_sort(RandomAccessIterator first, RandomAccessIterator last) {
    if (std::distance(first, last) < 2) return;
    RandomAccessIterator middle = AADS::middle(first, last);
    merge_sort(first, middle);
    merge_sort(middle, last);
    merge(first, middle, last);
}

// Merges data parts [begin, middle) and [middle, end) together.
template <typename RandomAccessIterator>
void merge(RandomAccessIterator begin, RandomAccessIterator middle, RandomAccessIterator end) {
    // The auxiliary vector we need.
    // We don't need to do the same to the right part because we start writing on the left part and
    // not on the right part so there is no risk of overwriting important data.
    std::vector<typename std::iterator_traits<RandomAccessIterator>::value_type> left(begin, middle);
    RandomAccessIterator current = begin;
    RandomAccessIterator l_iter = left.begin();
    RandomAccessIterator r_iter = middle;
    while (l_iter != left.end() && r_iter != end) {
        *current++ = (*l_iter < *r_iter) ? *l_iter++ : *r_iter++;
    }
    // Dump what remains in the left part, if there remains anything.
    while (l_iter != left.end()) *current++ = *l_iter++;
    // It is not necessary to drop what remains in the right part as it would be simply
    // overwriting what was there on the first place.
}