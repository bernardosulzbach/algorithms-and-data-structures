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
    Segment(const Point&, const Point&);
    Point getA() const;
    Point getB() const;
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
    const std::vector<Point> getPoints() const;
    const std::vector<Segment> getSegments() const;
private:
    std::vector<Point> points;
};

/** \brief Evaluates the area of a Polygon. The vertices must be in CCW (counter clockwise) order.
 *
 * \param poly const Polygon&
 * \return double
 */
double area(const Polygon& poly);

bool inside_polygon(const Polygon& poly, const Point& point);
