#include "stdafx.h"
#include "CppUnitTest.h"

#include <vector>

#include "..\algorithms-and-data-structures\utils.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace tests
{
    TEST_CLASS(Utils) {
public:
    TEST_METHOD(Peak) {
        std::vector<int> one_element = { 1 };
        Assert::AreEqual(1, *AADS::peak(one_element.begin(), one_element.end()));
        std::vector<int> two_elements = { 1, 2 };
        Assert::AreEqual(2, *AADS::peak(two_elements.begin(), two_elements.end()));
        std::vector<int> three_elements = { 1, 2, 3 };
        Assert::AreEqual(3, *AADS::peak(three_elements.begin(), three_elements.end()));
        std::vector<int> four_elements = { 4, 3, 2, 1};
        Assert::AreEqual(4, *AADS::peak(four_elements.begin(), four_elements.end()));
    }
    };
}