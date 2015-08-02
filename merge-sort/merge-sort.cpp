#include <algorithm>
#include <iterator>
#include <vector>

typedef std::vector<int>::size_type size_t;

// Merges data parts [start, middle) and [middle, end) together.
void merge(std::vector<int>& data, const size_t start, const size_t middle, const size_t end) {
    const auto left_begin = std::next(data.begin(), start);
    const auto left_end = std::next(data.begin(), middle);
    // The auxiliary vector we need.
    // We don't need to do the same to the right part because we start writing on the left part and
    // not on the right part so there is no risk of overwriting important data.
    const std::vector<int> left(left_begin, left_end);
    size_t l = 0;
    size_t r = middle;
    size_t cur = start;
    for (; l < left.size() && r < end; cur++) {
        if (left[l] < data[r]) {
            data[cur] = left[l];
            l++;
        }
        else {
            data[cur] = data[r];
            r++;
        }
    }
    if (l != left.size()) { // Dump what remains in the left part.
        while (l < left.size()) {
            data[cur] = left[l];
            l++;
            cur++;
        }
    }
    // It is not necessary to drop what remains in the right part as it would be simply
    // overwriting what was there on the first place.
}

// Sorts data in the range [start, end).
void merge_sort(std::vector<int>& data, const size_t start, const size_t end) {
    if (end - start < 2) return;
    size_t middle = (start + end) / 2;
    merge_sort(data, start, middle);
    merge_sort(data, middle, end);
    merge(data, start, middle, end);
}

// A merge sort implementation that uses O(1) + n / 2 auxiliary space.
void merge_sort(std::vector<int>& data) {
    merge_sort(data, 0, data.size());
}
