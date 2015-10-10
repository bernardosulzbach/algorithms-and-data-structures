#include "stdafx.h"
#include "CppUnitTest.h"

#include "..\algorithms-and-data-structures\string-interning.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace tests
{
	TEST_CLASS(StringInterningTests)
	{
	public:
		TEST_METHOD(ArrayBasedStringInterningInsertion)
        {
            ArrayBasedStringInterning interning;
            interning.add("a");
            Assert::IsTrue(interning.is_present("a"));
            Assert::IsFalse(interning.is_present("ba"));
        }
	};
}