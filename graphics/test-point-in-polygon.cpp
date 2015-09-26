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
    Point d(2.0, 2.0);
    Point e(0.0, 2.0);
    std::vector<Point> square_points = {a, b, d, e};
    Polygon square(square_points.begin(), square_points.end());
    std::cout << area(triangle) << "\n";
    return 0;
}
