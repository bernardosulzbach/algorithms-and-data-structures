#include <ctime>
#include <iostream>
#include <random>
#include <string>
#include <vector>

#include "trie.h"

// Inserts some strings from the vector, test for all.
void test(Trie& trie, std::vector<std::string> string_vector)
{
    // setf returns the flags before the function call. Store them to reset default later on.
    std::ios_base::fmtflags flags = std::cout.setf(std::ios_base::boolalpha);

    // Insert some strings.
    for (int i = string_vector.size() / 2; i > 0; i--)
    {
        std::string str = string_vector[rand() % string_vector.size()];
        std::cout << "Inserted \"" << str << "\" into the trie.\n";
        insert(trie, str);
    }

    // Test all.
    for (std::string str : string_vector) {
        std::cout << "\"" << str << "\" in trie? ";
        std::cout << contains(trie, str) << "\n";
    }

    std::cout.setf(flags);
}

int main() {
    srand(time(nullptr));
    Trie trie;
    //insert(trie, "test");
    std::cout << "Some tests...\n";
    std::vector<std::string> strings = { "", "a", "ab", "aba", "abb", "tes", "test" };
    test(trie, strings);
    return 0;
}
