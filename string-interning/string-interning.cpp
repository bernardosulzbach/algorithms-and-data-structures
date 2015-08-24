#include <iostream>
#include <string>
#include <vector>
#include <set>

class ArrayBasedStringInterning {
public:

    static const unsigned BLOCK_SIZE = 256;

    /** Adds a string to this interning and returns its ID. */
    unsigned add(const std::string& s) {
        unsigned index = UINT_MAX;
        unsigned block = 0; // The index on which the current block starts.
        for (char c : s) {
            if (block >= vector.size()) { // Ensure the vector is big enough.
                unsigned old_size = vector.size();
                vector.resize(old_size + BLOCK_SIZE, UINT_MAX);
                if (index != UINT_MAX) {
                    vector[index] = old_size;
                    block = vector[index];
                }
            }
            index = block + c; // The index of the current character.
            block = vector[index];
        }
        return index;
    }

    bool is_present(const std::string& s) {
        if (s.empty()) {
            return true;
        }
        unsigned index;
        unsigned block = 0;
        for (std::string::size_type i = 0; i < s.size() - 1; i++) {
            index = block + s[i];
            if (vector.size() <= index || vector[index] == UINT_MAX) {
                return false;
            }
            block = vector[index];
        }
        return true;
    }

private:
    std::vector<unsigned> vector;
};

class HashTableBasedStringInterning {
public:

    unsigned add(const std::string& s) {
        set.insert(s);
    }

    bool is_present(const std::string& s) {
        return set.find(s) != set.end();
    }

private:
    std::set<std::string> set;
};

int main() {
    ArrayBasedStringInterning interning;
    std::cout << interning.is_present("") << "\n";
    std::cout << interning.is_present("a") << "\n";
    std::cout << interning.add("a") << "\n";
    std::cout << interning.is_present("a") << "\n";
    std::cout << interning.add("aba") << "\n";
    std::cout << interning.is_present("ab") << "\n";
    std::cout << interning.is_present("aba") << "\n";
    std::cout << interning.is_present("abb") << "\n";
    std::cout << interning.is_present("abbc") << "\n";
    return 0;
}