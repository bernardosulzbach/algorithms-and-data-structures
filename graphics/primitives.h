#pragma once

#include <iostream>
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

std::ostream& operator<<(std::ostream&, const Point&);

class Segment {
public:
    Segment(const Point& first, const Point& second):
        a(first), b(second) {}
    Point getA() const;
    Point getB() const;
private:
    Point a;
    Point b;
};

class Polygon {
public:
    template <typename InputIterator>
    /** \brief Constructs a new Polygon. The vertices should be provided in CCW order.
     *
     * \param begin InputIterator
     * \param end InputIterator
     *
     */
    Polygon(InputIterator begin, InputIterator end) {
        copy(begin, end, std::back_inserter(points));
    }
    Polygon(const Point& sw, const Point& ne);
    std::vector<Point> getPoints() const;
    std::vector<Segment> getSegments() const;
private:
    std::vector<Point> points;
};

/** \brief Evaluates the area of a Polygon. The vertices must be in CCW (counter clockwise) order.
 *
 * \param poly const Polygon&
 * \return double
 */
double area(const Polygon&);

double distance(const Point&, const Point&);
double length(const Segment&);
double perimeter(const Polygon&);

bool inside_polygon(const Polygon& poly, const Point& point);

/** \brief Generates the convex hull of the given Polygon using Andrew's Monotone Chain.
 */
Polygon convex_hull(const Polygon& poly);
