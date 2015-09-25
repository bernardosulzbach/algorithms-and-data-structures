#include <iostream>
#include <vector>

#include "primitives.h"

int main() {
    Point a(0.0, 0.0);
    Point b(2.0, 0.0);
    Point c(1.0, 1.0);
    std::vector<Point> points;
    points.push_back(a);
    points.push_back(b);
    points.push_back(c);
    Polygon triangle(points.begin(), points.end());
    std::cout << (inside_polygon(triangle, a) == false) << "\n";
    std::cout << (inside_polygon(triangle, Point(1.0, .5)) == true) << "\n";
    std::cout << (inside_polygon(triangle, Point(1.0, 1.0)) == false) << "\n";
    std::cout << (inside_polygon(triangle, Point(2.0, 1.0)) == false) << "\n";
    std::cout << (inside_polygon(triangle, Point(0.0, .5)) == false) << "\n";
    std::cout << area(triangle) << "\n";

    return 0;
}
