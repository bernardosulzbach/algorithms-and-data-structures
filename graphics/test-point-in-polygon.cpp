#include <vector>

#include "primitives.h"

#include <iostream>

int main() {
    Point a(0.0, 0.0);
    Point b(2.0, 0.0);
    Point c(1.0, 1.0);
    std::vector<Point> points;
    points.push_back(a);
    points.push_back(b);
    points.push_back(c);
    Polygon triangle(points.begin(), points.end());
    std::cout << inside_polygon(triangle, a) << "\n";
    std::cout << inside_polygon(triangle, Point(.5, .5)) << "\n";
    return 0;
}
