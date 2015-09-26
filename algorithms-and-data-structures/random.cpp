#include <array>
#include <functional>
#include <vector>

#include "random.h"

std::mt19937 make_global_urng() {
    std::array<unsigned int, std::mt19937::state_size> seed_data;
    std::random_device rd;
    std::generate_n(seed_data.begin(), seed_data.size(), std::ref(rd));
    std::seed_seq seq(seed_data.begin(), seed_data.end());
    return std::mt19937(seq);
}

std::mt19937 &global_urng() {
    static std::mt19937 mt = make_global_urng();
    return mt;
}