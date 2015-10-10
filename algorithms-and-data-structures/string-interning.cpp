#include <string>
#include <vector>

#include "string-interning.h"

/** Adds a string to this interning and returns its ID. */
unsigned ArrayBasedStringInterning::add(const std::string& s) {
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

bool ArrayBasedStringInterning::is_present(const std::string& s) {
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