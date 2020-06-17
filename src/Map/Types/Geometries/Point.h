#include <array>
#include "Globe.hpp"

class Point {
protected:
    double latitude;
    double longitude;
    double precision;
    const Planet *planet;
public:
    Point(double latitude, double longitude);
    Point(double latitude, double longitude, double precision);
    Point(double latitude, double longitude, double precision, Planet planet);
    Point(double latitude, double longitude, Planet planet);
    ~Point();
    bool equals(const Point &point2);
    friend bool operator==(Point& point1, Point& point2);
    friend double distance(Point& point1, Point& point2);
};
