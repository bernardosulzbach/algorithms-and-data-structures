#include "stdafx.h"
#include "CppUnitTest.h"

#include "..\algorithms-and-data-structures\graphic-primitives.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace tests
{
	TEST_CLASS(GraphicPrimitivesTests) {
	public:
		TEST_METHOD(InsidePolygon) {
            Point a(0.0, 0.0);
            Point b(2.0, 0.0);
            Point c(1.0, 1.0);
            std::vector<Point> points = { a, b, c };
            Polygon triangle(points.begin(), points.end());
            // Vertices.
            Assert::IsFalse(inside_polygon(triangle, a));
            Assert::IsFalse(inside_polygon(triangle, b));
            Assert::IsFalse(inside_polygon(triangle, c));
            // Inside.
            Assert::IsTrue(inside_polygon(triangle, Point(1.0, .5)));
            Assert::IsTrue(inside_polygon(triangle, Point(0.5, .45)));
            Assert::IsTrue(inside_polygon(triangle, Point(1.5, .45)));
            // Outside.
            Assert::IsFalse(inside_polygon(triangle, Point(0.0, 1.0)));
            Assert::IsFalse(inside_polygon(triangle, Point(2.0, 1.0)));
            Assert::IsFalse(inside_polygon(triangle, Point(1.0, 2.0)));
		}
	};
}