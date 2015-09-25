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

class Polygon {
public:
    const std::vector<Point> getPoints() const {
        return points;
    }
private:
    std::vector<Point> points;
};
