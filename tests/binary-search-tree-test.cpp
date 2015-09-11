#include "stdafx.h"
#include "CppUnitTest.h"

#include <string>
#include <vector>

#include "..\algorithms-and-data-structures\binary_search_tree.h"
#include "..\algorithms-and-data-structures\utils.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace tests
{
    TEST_CLASS(BinarySearchTreeTest) {
public:
    TEST_METHOD(TestBinarySearchTree) {
        BinarySearchTree<int> tree;
        std::vector<int> values = { 0, 2, 3, 5, 8 };
        const int minimum = 0;
        const int maximum = 8;
        for (int value : values) tree.insert(value);
        for (int i = 0; i < 10; ++i) Assert::AreEqual(in_vector(values, i), tree.contains(i));
        Assert::AreEqual(minimum, tree.min());
        Assert::AreEqual(maximum, tree.max());
    }
    };
}