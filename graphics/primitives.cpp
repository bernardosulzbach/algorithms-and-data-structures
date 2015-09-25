#include <cmath>
#include <iostream>
#include <vector>

class Point {
public:
    Point(double x_coordinate, double y_coordinate):
        x(x_coordinate), y(y_coordinate) {}
    double getX() const {
        return x;
    }
    double getY() const {
        return y;
    }
private:
    double x;
    double y;
};

// As described by Herb Sutter and Scott Meyers, prefer non-friend non-member functions to member
// functions, to help increase encapsulation.
std::ostream& operator<<(std::ostream& os, const Point& point) {
    os << "(" << point.getX() << ", " << point.getY() << ")";
    return os;
}

class Segment {
public:
    Segment(const Point& first, const Point& second): a(first), b(second) {}
    Point getA() const {
        return a;
    }
    Point getB() const {
        return b;
    }
private:
    const Point a;
    const Point b;
};

class Polygon {
public:
    const std::vector<Point> getPoints() const {
        return points;
    }
    const std::vector<Segment> getSegments() const {
        static std::vector<Segment> segments;
        if (segments.empty()) {
            auto poly_points_iter = getPoints().begin();
            Point lastPoint = *poly_points_iter++;
            while (poly_points_iter != getPoints().end()) {
                segments.push_back(Segment(lastPoint, *poly_points_iter));
                lastPoint = *poly_points_iter++;
            }
            segments.push_back(Segment(lastPoint, *getPoints().begin()));
        }
        return segments;
    }
private:
    std::vector<Point> points;
};

bool inside_polygon(const Polygon& poly, const Point& point) {
    unsigned int intersectionCount = 0;
    for (Segment segment : poly.getSegments()) {
        Point a = segment.getA();
        Point b = segment.getB();
        if (a.getY() < point.getY() && b.getY() < point.getY()) {
        } else if (a.getY() >= point.getY() && b.getY() >= point.getY()) {
        } else {
            if (a.getX() == b.getX()) {
                intersectionCount++;
            } else {
                // Calculate the intersection point of the ray and the segment between p1 and
                // p2.
                // We just multiply the x gap between these two points by the ratio between
                // the distance from the upper point of the segment and the total height of
                // the segment.
                double slope = (b.getY() - a.getY()) / (b.getX() - a.getX());
                double x_offset_from_a = (point.getY() - a.getY()) / slope;
                double x_of_intersection = a.getX() + x_offset_from_a;
                if (x_of_intersection >= point.getX()) {
                    intersectionCount++;
                }
            }
        }
    }
    return intersectionCount & 1;
}
