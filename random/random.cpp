#include "random.h"

#include <array>
#include <functional>
#include <vector>

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
//
//template <typename T>
//void call_random_choice_on_vector(const std::vector<T> &v) {
//    random_choice<T>(v.begin(), v.end());
//}
//
//#include <iostream>
//int main() {
//    std::vector<int> vector;
//    try {
//        call_random_choice_on_vector(vector);
//    }
//    catch (const std::invalid_argument&) {
//        // Expected.
//    }
//    vector.push_back(1);
//    call_random_choice_on_vector(vector);
//    vector.push_back(2);
//    call_random_choice_on_vector(vector);
//    return 0;
//}