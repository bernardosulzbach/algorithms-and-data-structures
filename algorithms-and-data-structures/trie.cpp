#include <string>

#include "trie.h"

void add_child(TrieNode *trie_node, char child_symbol) {
    if (trie_node->child == nullptr) {
        trie_node->child = new TrieNode(child_symbol);
    }
    else {
        TrieNode *last_child = trie_node->child;
        while (last_child->next != nullptr) last_child = last_child->next;
        last_child->next = new TrieNode(child_symbol);
    }
}

bool has_child(TrieNode *trie_node, char child_symbol) {
    for (TrieNode *child = trie_node; child != nullptr; child = child->next)
        if (child->symbol == child_symbol) return true;
    return false;
}

void insert(Trie& trie, const std::string& str) {
    TrieNode *cur = trie.root_node;
    for (char c : str) {
        TrieNode *child = cur->child;
        while (child != nullptr) {
            if (child->symbol == c) {
                cur = child;
                break;
            }
            else {
                child = child->next;
            }
        }
        // Did not find a suitable child. Create one.
        if (child == nullptr) {
            if (cur->child == nullptr) {
                cur->child = new TrieNode(c);
                cur = cur->child;
            }
            else {
                TrieNode *last_child = cur->child;
                while (last_child->next != nullptr) last_child = last_child->next;
                last_child->next = new TrieNode();
                cur = last_child->next;
            }
            cur->symbol = c;
        }
    }
    if (!has_child(cur, '\0')) add_child(cur, '\0');
}

bool contains(const Trie& trie, const std::string& str) {
    TrieNode *cur = trie.root_node->child;
    for (char c : str) {
        if (cur == nullptr) return false; // Expected a node.
        while (true) {
            if (cur->symbol == c) {
                cur = cur->child;
                break;
            }
            cur = cur->next;
            if (cur == nullptr) return false;
        }
    }
    return has_child(cur, '\0');
}
