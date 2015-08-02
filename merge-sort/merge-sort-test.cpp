#include <algorithm>
#include <iostream>
#include <string>

#include "merge-sort.h"

std::string ok_or_bad_from_boolean(bool b) {
    return b ? "OK" : "BAD";
}

void test_empty_vector() {
    std::cout << "Empty vector test: ";
    std::vector<int> empty;
    merge_sort(empty);
    std::cout << ok_or_bad_from_boolean(true) << "\n";
}

void test_single_element_vector() {
    std::cout << "Single element vector test: ";
    std::vector<int> single_element = { 1 };
    merge_sort(single_element);
    std::cout << ok_or_bad_from_boolean(true) << "\n";
}

void test_common_case() {
    std::cout << "Multiple element vector test: " << "\n";
    std::vector<int> vector = { 3, 2, 4, 1, 5, 5, 5 };
    std::vector<int> sorted = { 1, 2, 3, 4, 5, 5, 5 };
    std::cout << "  Before sorting, vectors are different: ";
    std::cout << ok_or_bad_from_boolean(!std::equal(vector.begin(), vector.end(), sorted.begin())) << "\n";
    merge_sort(vector);
    std::cout << "  After sorting, vectors are equal: ";
    std::cout << ok_or_bad_from_boolean(std::equal(vector.begin(), vector.end(), sorted.begin())) << "\n";
}

int main() {
    test_empty_vector();
    test_single_element_vector();
    test_common_case();
    return 0;
}