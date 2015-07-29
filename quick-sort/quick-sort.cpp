#include <algorithm>
#include <vector>

// Sorts the vector in the range [begin, end).
void quicksort(std::vector<int>& vector, std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    auto const dist = std::distance(begin, end);
    if (dist < 2) return; // Trivially sorted.
    auto const pivot = std::next(begin, dist / 2);
    // Where the sorting happens.
    // std::nth_element is a partial sorting algorithm that rearranges elements in [first, last) such that:
    //    The element pointed at by nth is changed to whatever element would occur in that position if [first, last) was sorted.
    //    All of the elements before this new nth element are less than or equal to the elements after the new nth element.
    std::nth_element(begin, pivot, end);
    quicksort(vector, begin, pivot);
    quicksort(vector, pivot, end);
}

void quicksort(std::vector<int>& vector) {
    quicksort(vector, vector.begin(), vector.end());
}