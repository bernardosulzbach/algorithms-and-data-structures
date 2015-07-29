#include <algorithm>
#include <vector>

void insertion_sort(std::vector<int>& vector) {
    if (vector.size() < 2) {
        return;
    }
    const auto begin = vector.begin();
    const auto end = vector.end();
    for (auto i = std::next(begin); i != end; i++) {
        // std::upper_bound(first, last, val)
        //    Returns an iterator pointing to the first element in the range [first, last)
        //    which compares greater than val or last if no such element exists.
        // std::rotate(first, n_first, last)
        //    Performs a left rotation on a range of elements.
        //    Specifically, std::rotate swaps the elements in the range [first, last)
        //    in such a way that the element n_first becomes the first element of the new
        //    range and n_first - 1 becomes the last element.
        std::rotate(std::upper_bound(begin, i, *i), i, std::next(i));
    }
}