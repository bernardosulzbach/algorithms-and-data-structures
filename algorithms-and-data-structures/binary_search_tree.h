#pragma once

template <typename T>
class BinarySearchTree {
private:
    bool initialized = false;
    T value;
    BinarySearchTree<T> *parent = nullptr;
    BinarySearchTree<T> *l = nullptr;
    BinarySearchTree<T> *r = nullptr;

public:
    BinarySearchTree();

    BinarySearchTree(T t);

    ~BinarySearchTree();

    // Checks if a given element is on the tree.
    bool contains(T t) const;

    // Inserts an element into the tree.
    // Returns true if the element was inserted.
    bool insert(T t);

    // Erases an element.
    void erase(T t);

    // Finds the minimum element of the tree.
    T min() const;

    // Finds the maximum element of the tree.
    T max() const;
};

template <typename T>
BinarySearchTree<T>::BinarySearchTree() {};

template <typename T>
BinarySearchTree<T>::BinarySearchTree(T t) {
    value = t;
    initialized = true;
};

template <typename T>
BinarySearchTree<T>::~BinarySearchTree() {};

template <typename T>
bool BinarySearchTree<T>::contains(T t) const {
    if (!initialized) {
        return false;
    }
    else if (t < value) {
        if (l == nullptr) {
            return false;
        }
        else {
            return l->contains(t);
        }
    }
    else if (t == value) {
        return true;
    }
    else {
        if (r == nullptr) {
            return false;
        }
        else {
            return r->contains(t);
        }
    }
}

template <typename T>
bool BinarySearchTree<T>::insert(T t) {
    if (contains(t)) {
        return false;
    }
    if (!initialized) {
        value = t;
        initialized = true;
        return true;
    }
    if (t < value) {
        if (l == nullptr) {
            BinarySearchTree<T>* child = new BinarySearchTree<T>(t);
            child->parent = this;
            l = child;
            return true;
        }
        else {
            return l->insert(t);
        }
    }
    else {
        if (r == nullptr) {
            BinarySearchTree<T>* child = new BinarySearchTree<T>(t);
            child->parent = this;
            r = child;
            return true;
        }
        else {
            return r->insert(t);
        }
    }
}

template <typename T>
T BinarySearchTree<T>::min() const {
    const BinarySearchTree* pointer = this;
    while (pointer->l != nullptr) {
        pointer = pointer->l;
    }
    return pointer->value;
}

template <typename T>
T BinarySearchTree<T>::max() const {
    const BinarySearchTree* pointer = this;
    while (pointer->r != nullptr) {
        pointer = pointer->r;
    }
    return pointer->value;
}
