#pragma once

template <typename T>
class BinarySearchTree {
private:
    T value;
    BinarySearchTree<T>* parent;
    BinarySearchTree<T>* l;
    BinarySearchTree<T>* r;

public:
    BinarySearchTree();

    BinarySearchTree(T t);

    ~BinarySearchTree();

    // Checks if a given element is on the tree.
    bool contains(const T t) const;

    // Inserts an element into the tree.
    // Returns true if the element was inserted.
    bool insert(const T t);

    // Erases an element.
    void erase(const T t);

    // Finds the minimum element of the tree.
    T min() const;

    // Finds the maximum element of the tree.
    T max() const;
};

template <typename T>
BinarySearchTree<T>::BinarySearchTree() {};

template <typename T>
BinarySearchTree<T>::BinarySearchTree(const T t) {
    value = t;
};

template <typename T>
BinarySearchTree<T>::~BinarySearchTree() {};

template <typename T>
bool BinarySearchTree<T>::contains(const T t) const {
    if (value == NULL) {
        return false;
    }
    else if (t < value) {
        if (l == NULL) {
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
        if (r == NULL) {
            return false;
        }
        else {
            return r->contains(t);
        }
    }
}

template <typename T>
bool BinarySearchTree<T>::insert(const T t) {
    if (contains(t)) {
        return false;
    }
    if (value == NULL) {
        value = t;
        return true;
    }
    if (t < value) {
        if (l == NULL) {
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
        if (r == NULL) {
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
    while (pointer->l != NULL) {
        pointer = pointer->l;
    }
    return pointer->value;
}

template <typename T>
T BinarySearchTree<T>::max() const {
    const BinarySearchTree* pointer = this;
    while (pointer->r != NULL) {
        pointer = pointer->r;
    }
    return pointer->value;
}
