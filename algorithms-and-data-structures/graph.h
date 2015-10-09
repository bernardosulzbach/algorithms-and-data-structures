#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// A simple graph implementation.
class Graph {
public:
    Graph() {}
    Graph(const std::string& str);

    const bool directed = false;
    unsigned v_count = 0;
    unsigned e_count = 0;

    static const unsigned nvertex = UINT_MAX;
    static const unsigned nparent = nvertex - 1;
    static const std::pair<unsigned, unsigned> nedge;

    std::vector<std::vector<unsigned>> adj_list;

    // Inserts the specified amount of vertices to the graph.
    // This has O(n) time complexity.
    void insert_vertices(unsigned n);

    // Erases a vertex.
    void erase_vertex(unsigned vertex);

    // Inserts an undirected edge connecting a and b.
    // Returns true if successful.
    bool insert_edge(unsigned a, unsigned b);

    // Erases the edge (a, b). Returns true if successful.
    bool erase_edge(unsigned a, unsigned b);

    // Erase all edges that start or end at the given vertex.
    void isolate_vertex(unsigned vertex);

    // Counts how many connected components a Graph has.
    unsigned connected_components() const;

    // Returns a shortest path from a to b.
    std::vector<unsigned> shortest_path(unsigned a, unsigned b) const;

    // Finds a cycle in the graph using DFS.
    // Returns the edge responsible by the cycle.
    // If no or cycle was found, returns Graph::nedge.
    std::pair<unsigned, unsigned> find_cycle() const;

    // Convenience function that calls find_cycle.
    bool has_cycle() const;

    // Verifies if the graph is bipartite,
    bool is_bipartite() const;
};


inline std::ostream& operator<<(std::ostream& ostr, const Graph& graph) {
    typedef std::vector<std::vector<unsigned>>::size_type size_type;
    size_type size = graph.adj_list.size();
    for (size_type i = 0; i < size; ++i) {
        ostr << i << ':';
        for (unsigned adjacent : graph.adj_list[i]) {
            ostr << adjacent << ' ';
        }
        ostr << '\n';
    }
    return ostr;
}