#include <algorithm>
#include <queue>
#include <stack>
#include <sstream>
#include <string>
#include <vector>

#include "graph.h"
#include "utils.h"

typedef std::vector<unsigned>::const_iterator citer;

const std::pair<unsigned, unsigned> Graph::nedge = std::make_pair(Graph::nvertex, Graph::nvertex);

Graph::Graph(const std::string &str) {
    unsigned vertices = std::count(str.begin(), str.end(), '\n');
    insert_vertices(vertices);
    typedef std::string::size_type size_type;
    size_type last_semicolon = 0;
    unsigned cur_vertex = 0;
    while ((last_semicolon = str.find(':', last_semicolon + 1)) != std::string::npos) {
        size_type next_newline = str.find('\n', last_semicolon);
        size_type diff = next_newline - last_semicolon;
        if (diff > 1) {
            std::stringstream ss(str.substr(last_semicolon + 1, diff - 1));
            unsigned x;
            while (ss >> x) {
                insert_edge(cur_vertex, x);
            }
        }
        cur_vertex += 1;
    }
}

void Graph::insert_vertices(unsigned n) {
    v_count += n;
    while (n--) {
        adj_list.push_back(std::vector<unsigned>());
    }
}

void Graph::erase_vertex(unsigned vertex) {
    // Delegate the hard work to isolate_vertex.
    isolate_vertex(vertex);
    // Subract a vertex from the counter.
    v_count--;
    adj_list.erase(adj_list.begin() + vertex);
}

bool Graph::has_edge(unsigned a, unsigned b) {
    return AADS::in_vector(adj_list[a], b);
}

bool Graph::insert_edge(unsigned a, unsigned b) {
    if (v_count > std::max(a, b)) {
        // Currently, all Graphs are undirected.
        // Therefore, if (a, b) does not exist, (b, a) also does not.
        citer result = std::find(adj_list[a].begin(), adj_list[a].end(), b);
        if (result == adj_list[a].end()) {
            adj_list[a].push_back(b);
            adj_list[b].push_back(a);
            e_count++;
            return true;
        }
    }
    return false;
}

bool Graph::erase_edge(unsigned a, unsigned b) {
    // If (a, b) exists, delete (a, b).
    citer result = std::find(adj_list[a].begin(), adj_list[a].end(), b);
    if (result != adj_list[a].end()) {
        adj_list[a].erase(result);
        // As currently all graphs are undirected, (b, a) also exists.
        result = std::find(adj_list[b].begin(), adj_list[b].end(), a);
        adj_list[b].erase(result);
        // They count as a single edge.
        e_count--;
        return true;
    }
    return false;
}

void Graph::isolate_vertex(unsigned vertex) {
    // Decrement the edge count.
    e_count -= adj_list[vertex].size();
    adj_list[vertex].clear();
    // Delete all edges towards this vertex.
    for (std::vector<unsigned>& edges : adj_list) {
        citer result = std::find(edges.begin(), edges.end(), vertex);
        if (result != edges.end()) {
            edges.erase(std::find(edges.begin(), edges.end(), vertex));
        }
    }
}

unsigned Graph::connected_components() const {
    unsigned count = 0;
    std::vector<bool> found(v_count, false);
    for (unsigned i = 0; i < v_count; ++i) {
        if (!found[i]) {
            std::queue<unsigned> queue;
            queue.push(i);
            found[i] = true;
            while (!queue.empty()) {
                unsigned cur_vertex = queue.front();
                queue.pop();
                for (unsigned vertex : adj_list[cur_vertex]) {
                    if (!found[vertex]) {
                        found[vertex] = true;
                        queue.push(vertex);
                    }
                }
            }
            count++;
        }
    }
    return count;
}

std::vector<unsigned> Graph::shortest_path(unsigned a, unsigned b) const {
    std::vector<unsigned> parents(v_count, nvertex);
    std::queue<unsigned> queue;
    queue.push(a);
    parents[a] = nparent;
    while (!queue.empty()) {
        unsigned current = queue.front();
        queue.pop();
        if (current == b) {
            break;
        }
        for (unsigned node : adj_list[current]) {
            if (parents[node] == nvertex) {
                queue.push(node);
                parents[node] = current;
            }
        }
    }
    std::vector<unsigned> path;
    unsigned current = b;
    while (current != nparent) {
        path.push_back(current);
        current = parents[current];
    }
    std::reverse(path.begin(), path.end());
    return path;
}

std::pair<unsigned, unsigned> Graph::find_cycle() const {
    std::vector<unsigned> parent(v_count, nvertex);
    for (unsigned i = 0; i < v_count; ++i) {
        if (parent[i] == nvertex) {
            std::stack<unsigned> stack;
            stack.push(i);
            parent[i] = nparent;
            while (!stack.empty()) {
                unsigned current = stack.top();
                stack.pop();
                for (unsigned vertex : adj_list[current]) {
                    // If the vertex has a parent...
                    if (parent[vertex] != nvertex) {
                        // and it is not the parent of the current vertex,
                        if (vertex != parent[current]) {
                            // there is a loop.
                            return std::make_pair(current, vertex);
                        }
                    }
                    else {
                        parent[vertex] = current;
                        stack.push(vertex);
                    }
                }
            }
        }
    }
    return nedge;
}

bool Graph::has_cycle() const {
    return find_cycle() != nedge;
}

bool Graph::is_bipartite() const {
    std::vector<bool> visited(v_count);
    std::vector<bool> flavour(v_count);  // Simulates two colors.
    for (unsigned i = 0; i < v_count; ++i) {
        if (!visited[i]) {
            std::queue<unsigned> queue;
            queue.push(i);
            visited[i] = true;
            while (!queue.empty()) {
                unsigned cur_vertex = queue.front();
                queue.pop();
                for (unsigned vertex : adj_list[cur_vertex]) {
                    if (visited[vertex]) {
                        if (flavour[vertex] == flavour[cur_vertex]) {
                            return false;
                        }
                    }
                    else {
                        visited[vertex] = true;
                        flavour[vertex] = !flavour[cur_vertex];
                        queue.push(vertex);
                    }
                }
            }
        }
    }
    return true;
}