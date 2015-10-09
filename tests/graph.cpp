#include "stdafx.h"
#include "CppUnitTest.h"

#include "..\algorithms-and-data-structures\graph.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace tests
{
    TEST_CLASS(GraphTests) {
public:
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