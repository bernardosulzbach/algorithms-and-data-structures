#include "stdafx.h"
#include "CppUnitTest.h"

#include "..\algorithms-and-data-structures\graph.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace tests
{
    TEST_CLASS(GraphTests) {
public:
    TEST_METHOD(GraphVertexInsertion) {
        Graph g;
        const unsigned ZERO = 0;
        const unsigned TEN = 10;
        g.insert_vertices(ZERO);
        Assert::IsTrue(ZERO == g.v_count);
        g.insert_vertices(TEN);
        Assert::IsTrue(TEN == g.v_count);
    }
    TEST_METHOD(GraphTrivialShortestPath) {
        Graph g;
        g.insert_vertices(1);
        std::vector<unsigned> path = g.shortest_path(0, 0);
        Assert::IsTrue(path.size() == 1);
        Assert::IsTrue(path[0] == 0);
    }
    TEST_METHOD(GraphNontrivialShortestPath) {
        Graph g;
        g.insert_vertices(4);
        g.insert_edge(0, 1);
        g.insert_edge(0, 3); // Shortest path: 0 -> 3
        g.insert_edge(1, 2);
        g.insert_edge(1, 3); // Average path: 0 -> 1 -> 3
        g.insert_edge(2, 3); // Longest path: 0 -> 1 -> 2 -> 3
        std::vector<unsigned> path = g.shortest_path(0, 3);
        Assert::IsTrue(path.size() == 2);
        Assert::IsTrue(path[0] == 0);
        Assert::IsTrue(path[1] == 3);
    }
    TEST_METHOD(GraphIsolateVertex) {
        Graph g;
        g.insert_vertices(2);
        Assert::IsFalse(g.has_edge(0, 1));
        g.insert_edge(0, 1);
        Assert::IsTrue(g.has_edge(0, 1));
        g.isolate_vertex(0);
        Assert::IsFalse(g.has_edge(0, 1));
    }
    TEST_METHOD(GraphCycleFinding) {
        Graph g;
        g.insert_vertices(4);
        g.insert_edge(0, 1);
        g.insert_edge(1, 2);
        g.insert_edge(2, 3);
        g.insert_edge(3, 0);
        std::pair<unsigned, unsigned> cycle = g.find_cycle();
        Assert::IsFalse(Graph::nedge == cycle);
        g.erase_edge(cycle.first, cycle.second);
        Assert::IsTrue(Graph::nedge == g.find_cycle());
    }
    };
}