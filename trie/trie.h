#include <string>

struct TrieNode {
    char symbol;
    TrieNode *next = nullptr; // The next child of the parent of this node.
    TrieNode *child = nullptr; // The first child of this node.

    TrieNode() {}
    TrieNode(char node_symbol) {
        symbol = node_symbol;
    }
};

struct Trie {
    TrieNode *root_node = new TrieNode();
};

void insert(Trie& trie, const std::string& str);

bool contains(const Trie& trie, const std::string& str);