#include "stdafx.h"
#include "CppUnitTest.h"

#include <vector>

#include "..\algorithms-and-data-structures\insertion-sort.h"
#include "..\algorithms-and-data-structures\merge-sort.h"
#include "..\algorithms-and-data-structures\quick-sort.h"
#include "..\algorithms-and-data-structures\utils.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace tests
{
    TEST_CLASS(SortingTest) {
public:
    TEST_METHOD(InsertionSort) {
        std::vector<int> empty;
        insertion_sort(empty.begin(), empty.end());
        std::vector<int> single_element_vector = { 3 };
        insertion_sort(single_element_vector.begin(), single_element_vector.end());
        std::vector<int> random = { 3, 2, 4, 1, 5, 5, 5 };
        std::vector<int> sorted = { 1, 2, 3, 4, 5, 5, 5 };
        insertion_sort(random.begin(), random.end());
        Assert::IsTrue(random == sorted);
    }
    TEST_METHOD(MergeSort) {
        std::vector<int> empty;
        merge_sort(empty.begin(), empty.end());
        std::vector<int> single_element_vector = { 3 };
        merge_sort(single_element_vector.begin(), single_element_vector.end());
        std::vector<int> random = { 3, 2, 4, 1, 5, 5, 5 };
        std::vector<int> sorted = { 1, 2, 3, 4, 5, 5, 5 };
        merge_sort(random.begin(), random.end());
        Assert::IsTrue(random == sorted);
    }
    TEST_METHOD(QuickSort) {
        std::vector<int> empty;
        quick_sort(empty.begin(), empty.end());
        std::vector<int> single_element_vector = { 3 };
        quick_sort(single_element_vector.begin(), single_element_vector.end());
        std::vector<int> random = { 3, 2, 4, 1, 5, 5, 5 };
        std::vector<int> sorted = { 1, 2, 3, 4, 5, 5, 5 };
        quick_sort(random.begin(), random.end());
        Assert::IsTrue(random == sorted);
    }
    };
}