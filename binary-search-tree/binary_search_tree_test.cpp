#include <iostream>
#include <iomanip>

#include "binary_search_tree.h"

using namespace std;

int main() {
    BinarySearchTree<int> tree;
    // Insert some stuff.
    int values[] = { 2, 3, 6, 4, 5 };
    for (int value : values) {
        tree.insert(value);
        cout << "Inserted " << value << " into the tree.\n";
    }
    // Check the contents.
    int checks[] = { 0, 2, 5, 6, 8, 200 };
    cout << boolalpha;
    for (int check : checks) {
        cout << "contains(" << setw(4) << check << ") = " << tree.contains(check) << "\n";
    }
    // Get minimum and maximum.
    cout << "min() = " << tree.min() << "\n";
    cout << "max() = " << tree.max() << "\n";
    return 0;
}