#include <algorithm>
#include <iostream>

#include "segment_tree.h"

// Calculates the size of the segment tree array.
// 2 * p - 1 where p is the next power of two greater than or equal to source_size.
unsigned size_of_segment_tree(unsigned source_size) {
    unsigned size = 1;
    while (size < source_size) size <<= 1;
    return size << 1 - 1;
}

void construct_tree(int source[], int tree[], int low, int high, int pos) {
    if (low == high) {
        tree[pos] = source[low];
    }
    else {
        int mid = (low + high) / 2;
        construct_tree(source, tree, low, mid, 2 * pos + 1);
        construct_tree(source, tree, mid + 1, high, 2 * pos + 2);
        tree[pos] = std::min(tree[2 * pos + 1], tree[2 * pos + 2]);
    }
}

int range_min_query(int tree[], int query_low, int query_high, int low, int high, int pos) {
    if (query_low <= low && query_high >= high) { // Total overlap.
        return tree[pos];
    }
    else if (query_low > high || query_high < low) { // No overlap.
        return INT_MAX;
    }
    else {
        int mid = (low + high) / 2;
        int left = range_min_query(tree, query_low, query_high, low, mid, 2 * pos + 1);
        int right = range_min_query(tree, query_low, query_high, mid + 1, high, 2 * pos + 2);
        return std::min(left, right);
    }
}

int main() {
    int source[] = { 1, 4, 3, 2, 1, 0, 2, 3 };
    int tree[64];
    construct_tree(source, tree, 0, 7, 0);
    std::cout << range_min_query(tree, 0, 3, 0, 7, 0) << '\n';
    std::cout << range_min_query(tree, 4, 7, 0, 7, 0) << '\n';
    std::cout << range_min_query(tree, 0, 7, 0, 7, 0) << '\n';
    return 0;
}