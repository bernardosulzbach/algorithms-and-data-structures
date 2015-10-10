#include "stdafx.h"
#include "CppUnitTest.h"

#include <algorithm>
#include <string>
#include <vector>

#include "..\algorithms-and-data-structures\trie.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include <iostream>

namespace tests
{
    TEST_CLASS(TrieTest) {
public:
    TEST_METHOD(TrieSingleInsertion) {
        Trie trie;
        insert(trie, "a");
        Assert::IsTrue(contains(trie, "a"));
        Assert::IsFalse(contains(trie, "b"));
    }
    TEST_METHOD(TrieHeavyInsertion) {
        Trie trie;
        std::vector<std::string> strings = { "", "a", "b", "aa", "ab", "bb", "aaa", "aab", "abb", "bbb" };
        std::vector<std::string> inserted;
        std::vector<std::string> not_inserted;
        // Use 3/4 of the permutations.
        const short insert_before_skipping = 3;
        short counter = 0;
        for (auto string : strings) {
            bool got_larger_permutation = false;
            do {
                got_larger_permutation = std::next_permutation(string.begin(), string.end());
                if (counter == insert_before_skipping) {
                    counter = 0; // Reset the counter, do not add this permutation.
                    not_inserted.push_back(string);
                }
                else {
                    insert(trie, string);
                    inserted.push_back(string);
                    ++counter;
                }
            } while (got_larger_permutation);
        }
        // Verify all of them.
        for (auto string : inserted) Assert::IsTrue(contains(trie, string));
        for (auto string : not_inserted) Assert::IsFalse(contains(trie, string));
    }
    };
}
