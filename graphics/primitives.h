#pragma once

#include <vector>

class Point {
public:
    Point(double x_coordinate, double y_coordinate):
        x(x_coordinate), y(y_coordinate) {}
    double getX() const;
    double getY() const;
private:
    double x;
    double y;
};

class Polygon {
public:
    template <typename InputIterator>
    Polygon(InputIterator begin, InputIterator end) {
        copy(begin, end, std::back_inserter(points));
    }
    const std::vector<Point> getPoints() const;
private:
    std::vector<Point> points;
};

bool inside_polygon(const Polygon& poly, const Point& point) {
    return false;
}
