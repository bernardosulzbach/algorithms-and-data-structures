#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <vector>

#include "graphic-primitives.h"

Point::Point(): x(0), y(0) {}

double Point::getX() const {
    return x;
}

double Point::getY() const {
    return y;
}

// As described by Herb Sutter and Scott Meyers, prefer non-friend non-member functions to member
// functions, to help increase encapsulation.
std::ostream& operator<<(std::ostream& os, const Point& point) {
    os << "(" << point.getX() << ", " << point.getY() << ")";
    return os;
}

bool operator!=(const Point& a, const Point& b) {
    return a.getX() != b.getX() || a.getY() != b.getY();
}

Point Segment::getA() const {
    return a;
}
Point Segment::getB() const {
    return b;
}

Polygon::Polygon(const Point& sw, const Point& ne) {
    std::vector<Point> rect = {sw, Point(ne.getX(), sw.getY()), ne, Point(sw.getX(), ne.getY())};
    copy(rect.begin(), rect.end(), std::back_inserter(points));
}

std::vector<Point> Polygon::getPoints() const {
    return points;
}

std::vector<Segment> Polygon::getSegments() const {
    static std::vector<Segment> segments;
    if (segments.empty()) {
        for (auto i = 1U; i < getPoints().size(); ++i) {
            segments.push_back(Segment(getPoints()[i - 1], getPoints()[i]));
        }
        segments.push_back(Segment(getPoints().back(), getPoints().front()));
    }
    return segments;
}

double area(const Polygon& poly) {
    double sum = 0;
    for (Segment segment : poly.getSegments()) {
        sum += (segment.getB().getY() - segment.getA().getY()) * (segment.getA().getX() + segment.getB().getX());
    }
    return sum / 2;
}

double distance(const Point& a, const Point& b) {
    return std::sqrt(std::pow(a.getX() - b.getX(), 2) + std::pow(a.getY() - b.getY(), 2));
}

double length(const Segment& seg) {
    return distance(seg.getA(), seg.getB());
}

double perimeter(const Polygon& poly) {
    double sum = 0;
    for (Segment segment : poly.getSegments()) {
        sum += length(segment);
    }
    return sum;
}

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

double evaluate_ccw_determinant(const Point& a, const Point& b, const Point& c) {
    // Three points are a CCW turn if CCW > 0.
    //
    //       |p1.x p1.y 1|
    // CCW = |p2.x p2.y 1|
    //       |p3.x p3.y 1|
    //
    // This is just a factored form of the determinant:
    // (p2.x - p1.x)*(p3.y - p1.y) - (p2.y - p1.y)*(p3.x - p1.x)
    return (b.getX() - a.getX()) * (c.getY() - a.getY()) - (b.getY() - a.getY()) * (c.getX() - a.getX());
}

bool is_ccw_turn(const Point& a, const Point& b, const Point& c) {
    return evaluate_ccw_determinant(a, b, c) > 0;
}

bool is_not_cw_turn(const Point& a, const Point& b, const Point& c) {
    return evaluate_ccw_determinant(a, b, c) >= 0;
}

bool operator<(const Point& a, const Point& b) {
    return a.getX() < b.getX() || (a.getX() == b.getX() && a.getY() < b.getY());
}

/** Pass two hulls, both should go in CW direction!
 */
std::vector<Point> merge_hulls(const std::vector<Point>& upper_hull, const std::vector<Point>& lower_hull) {
    std::vector<Point> hull(upper_hull.begin(), upper_hull.end());
    auto lower_hull_iter = lower_hull.begin();
    if (*lower_hull_iter != *hull.rbegin()) hull.push_back(*lower_hull_iter);
    lower_hull_iter++;
    std::copy(lower_hull_iter, lower_hull.end()--, std::back_inserter(hull));
    if (*lower_hull_iter != *hull.begin()) hull.push_back(*lower_hull_iter);
    return hull;
}

// Using Andrew's Monotone Chain for Convex Hulls.
Polygon convex_hull(const Polygon& poly) {
    std::vector<Point> sorted_points(poly.getPoints());
    std::sort(sorted_points.begin(), sorted_points.end());
    auto iter = sorted_points.begin();
    auto lowest_leftmost = iter;
    auto highest_leftmost = iter++;
    while (iter->getX() == highest_leftmost->getX()) highest_leftmost = iter++; // Y can only be higher.
    iter = sorted_points.end()--;
    auto highest_rightmost = iter;
    auto lowest_rightmost = iter--;
    while (iter->getX() == lowest_rightmost->getX()) lowest_rightmost = iter--; // Y can only be lower.
    // Upper hull.
    std::vector<Point> upper_hull;
    upper_hull.push_back(*highest_leftmost);
    while (highest_leftmost != highest_rightmost) {
        while (upper_hull.size() >= 2 && is_not_cw_turn(upper_hull[upper_hull.size() - 2], upper_hull[upper_hull.size() - 1], *highest_leftmost)) {
            upper_hull.pop_back();
        }
        upper_hull.push_back(*highest_leftmost++);
    }
    upper_hull.push_back(*highest_leftmost); // Add the last point.
    // Lower hull.
    std::vector<Point> lower_hull;
    lower_hull.push_back(*lowest_rightmost);
    while (lowest_rightmost != lowest_leftmost) {
        while (lower_hull.size() >= 2 && is_not_cw_turn(lower_hull[lower_hull.size() - 2], lower_hull[lower_hull.size() - 1], *lowest_rightmost)) {
            lower_hull.pop_back();
        }
        lower_hull.push_back(*lowest_rightmost--);
    }
    lower_hull.push_back(*lowest_rightmost); // Add the last point.
    // Merge them.
    std::vector<Point> polygon_line = merge_hulls(upper_hull, lower_hull);
    // Make a polygon.
    std::reverse(polygon_line.begin(), polygon_line.end());
    return Polygon(polygon_line.begin(), polygon_line.end());
}
