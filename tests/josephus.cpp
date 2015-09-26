#include "stdafx.h"
#include "CppUnitTest.h"

#include "..\algorithms-and-data-structures\josephus.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace tests
{
    TEST_CLASS(JosephusProblem) {
public:
    TEST_METHOD(Josephus) {
        Assert::AreEqual(1, AADS::josephus(1));
        Assert::AreEqual(1, AADS::josephus(2));
        Assert::AreEqual(3, AADS::josephus(3));
        Assert::AreEqual(1, AADS::josephus(4));
        Assert::AreEqual(3, AADS::josephus(5));
        Assert::AreEqual(5, AADS::josephus(6));
    }
    };
}