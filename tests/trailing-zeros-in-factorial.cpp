#include "stdafx.h"
#include "CppUnitTest.h"

#include "..\algorithms-and-data-structures\trailing-zeros-in-factorial.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace tests
{
    TEST_CLASS(TrailingZeros) {
    public:
        TEST_METHOD(TrailingZerosInFactorial) {
            Assert::AreEqual(0U, trailing_zeros_in_factorial_of(0));
            Assert::AreEqual(0U, trailing_zeros_in_factorial_of(1));
            Assert::AreEqual(0U, trailing_zeros_in_factorial_of(2));
            Assert::AreEqual(0U, trailing_zeros_in_factorial_of(3));
            Assert::AreEqual(0U, trailing_zeros_in_factorial_of(4));
            Assert::AreEqual(1U, trailing_zeros_in_factorial_of(5));
            Assert::AreEqual(1U, trailing_zeros_in_factorial_of(6));
            Assert::AreEqual(1U, trailing_zeros_in_factorial_of(7));
            Assert::AreEqual(1U, trailing_zeros_in_factorial_of(8));
            Assert::AreEqual(1U, trailing_zeros_in_factorial_of(9));
            Assert::AreEqual(2U, trailing_zeros_in_factorial_of(10));
            Assert::AreEqual(2U, trailing_zeros_in_factorial_of(11));
            Assert::AreEqual(2U, trailing_zeros_in_factorial_of(12));
            Assert::AreEqual(2U, trailing_zeros_in_factorial_of(13));
            Assert::AreEqual(2U, trailing_zeros_in_factorial_of(14));
            Assert::AreEqual(3U, trailing_zeros_in_factorial_of(15));
            Assert::AreEqual(3U, trailing_zeros_in_factorial_of(16));
            Assert::AreEqual(3U, trailing_zeros_in_factorial_of(17));
            Assert::AreEqual(3U, trailing_zeros_in_factorial_of(18));
            Assert::AreEqual(3U, trailing_zeros_in_factorial_of(19));
            Assert::AreEqual(4U, trailing_zeros_in_factorial_of(20));
            Assert::AreEqual(4U, trailing_zeros_in_factorial_of(21));
            Assert::AreEqual(4U, trailing_zeros_in_factorial_of(22));
            Assert::AreEqual(4U, trailing_zeros_in_factorial_of(23));
            Assert::AreEqual(4U, trailing_zeros_in_factorial_of(24));
            Assert::AreEqual(6U, trailing_zeros_in_factorial_of(25));
        }
    };
}