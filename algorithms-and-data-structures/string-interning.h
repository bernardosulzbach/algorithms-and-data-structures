#pragma once

#include <string>
#include <vector>

class ArrayBasedStringInterning {
public:
    ArrayBasedStringInterning() {}
    ~ArrayBasedStringInterning() {}
    /** Adds a string to this interning and returns its ID. */
    unsigned add(const std::string&);
    bool is_present(const std::string&);
private:
    static const unsigned BLOCK_SIZE = 256;
    std::vector<unsigned> vector;
};
