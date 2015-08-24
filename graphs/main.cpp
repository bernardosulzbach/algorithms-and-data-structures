#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <sstream>
#include <string>
#include <vector>

#include "graph.h"

using std::vector;

////////////////////////////////////////////////////////////////////////////////
// Graph IO - Optional.
////////////////////////////////////////////////////////////////////////////////

// Converts a Graph to a string readable by both humans and computers.
// Calling from_string(to_string(g)) should produce a copy of g.
std::string to_string(const Graph* const g) {
    std::string str;
    typedef vector<vector<unsigned>>::size_type size_t;
    size_t size = g->adj_list.size();
    for (size_t i = 0; i < size; ++i) {
        str += std::to_string(i) + ':';
        for (unsigned adjacent : g->adj_list[i]) {
            str += std::to_string(adjacent) + ' ';
        }
        str += '\n';
    }
    return str;
}

// Converts a string to a Graph.
// Calling from_string(to_string(g)) should produce a copy of g.
Graph* from_string(const std::string& str) {
    Graph* g = new Graph();
    unsigned vertices = std::count(str.begin(), str.end(), '\n');
    g->insert_vertices(vertices);
    typedef std::string::size_type size_t;
    size_t last_semicolon = 0;
    unsigned cur_vertex = 0;
    while ((last_semicolon = str.find(':', last_semicolon + 1)) != std::string::npos) {
        size_t next_newline = str.find('\n', last_semicolon);
        size_t diff = next_newline - last_semicolon;
        if (diff > 1) {
            std::stringstream ss(str.substr(last_semicolon + 1, diff - 1));
            unsigned x;
            while (ss >> x) {
                g->insert_edge(cur_vertex, x);
            }
        }
        cur_vertex += 1;
    }
    return g;
}

////////////////////////////////////////////////////////////////////////////////
// Main - For testing purposes only.
////////////////////////////////////////////////////////////////////////////////

void print_path(const vector<unsigned>& path) {
    for (unsigned i = 0; i < path.size(); i++) {
        if (i > 0) {
            std::cout << " -> ";
        }
        std::cout << path.at(i);
    }
    std::cout << "\n";
}

std::string to_string(std::pair<unsigned, unsigned> pair) {
    std::string representation = "(";
    representation += std::to_string(pair.first);
    representation += ", ";
    representation += std::to_string(pair.second);
    representation += ")";
    return representation;
}

void find_cycle_test() {
    Graph* g = new Graph();
    g->insert_vertices(4);
    g->insert_edge(0, 1);
    g->insert_edge(1, 2);
    g->insert_edge(2, 3);
    g->insert_edge(3, 0);
    std::pair<unsigned, unsigned> cycle = g->find_cycle();
    std::cout << to_string(cycle) << "\n";
    g->erase_edge(cycle.first, cycle.second);
    std::cout << to_string(g->find_cycle()) << "\n";
}

int main() {
    // Make a simple Graph.
    Graph* g = new Graph();
    // Insert seven vertices.
    g->insert_vertices(7);
    // Insert some edges.
    g->insert_edge(2, 3);
    g->insert_edge(2, 4);
    g->insert_edge(2, 5);
    g->insert_edge(4, 5);
    // Check that it can handle a trivial shortest path case.
    print_path(g->shortest_path(2, 2));
    // 5 -> 2 -> 3 is the shortest path from 5 to 3.
    // Analogously, 3 -> 2 -> 5 it the shortest path from 3 to 5.
    print_path(g->shortest_path(5, 3));
    print_path(g->shortest_path(3, 5));
    // Erase a unimportant vertex.
    g->erase_vertex(6);
    // Isolate the vertex 2.
    g->isolate_vertex(2);
    g->insert_edge(0, 1);
    g->insert_edge(0, 3);
    g->insert_edge(1, 4);
    // Now the shortest path from 5 to 3 is 5, 4, 1, 0, 3.
    print_path(g->shortest_path(5, 3));
    print_path(g->shortest_path(3, 5));
    // Print the Graph.
    std::cout << to_string(g);
    // Connected component test.
    // There are two connected components here: {2} and {0, 1, 3, 4, 5}.
    std::cout << g->connected_components() << "\n";
    g->insert_vertices(2);
    std::cout << g->connected_components() << "\n";
    g->insert_edge(6, 7);
    std::cout << g->connected_components() << "\n";
    Graph* not_bipartite = new Graph();
    not_bipartite->insert_vertices(5);
    not_bipartite->insert_edge(0, 1);
    not_bipartite->insert_edge(1, 2);
    not_bipartite->insert_edge(2, 3);
    not_bipartite->insert_edge(3, 1);
    not_bipartite->insert_edge(1, 4);
    std::cout << g->is_bipartite() << "\n";
    std::cout << not_bipartite->is_bipartite() << "\n";
    find_cycle_test();
    return 0;
}