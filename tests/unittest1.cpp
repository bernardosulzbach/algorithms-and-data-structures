#include "stdafx.h"
#include "CppUnitTest.h"

#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "..\trie\trie.h"

namespace tests
{
    TEST_CLASS(TrieTest) {
public:
    TEST_METHOD(Test) {
        Trie trie;
        insert(trie, "testing");
        Assert::IsTrue(contains(trie, "testing"));
        Assert::IsFalse(contains(trie, "false"));
    }
    };
}