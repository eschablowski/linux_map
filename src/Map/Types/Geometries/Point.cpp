#include <math.h> /* sqrt */
#include "Point.h"
#include "Globe.hpp"
#include "config.h"

bool operator==(Point &point1, Point &point2)
{
    if (point1.planet != point2.planet)
        return false;
    return point1.planet->compareLongitude(point1.longitude, point2.longitude) && point1.planet->compareLatitude(point1.latitude, point2.latitude);
}

double distance(Point &point1, Point &point2)
{
    if(point1.planet != point2.planet){
        return distance(point1.planet, point2.planet)
    }
    const double latitudeDistance = (point1.latitude - point2.latitude) * point1.planet->circumferenceMeridional / 360.0;
    const double longitudeDistance = (point1.longitude - point2.longitude) * point1.planet->circumferenceEquatorial / 360.0;
    return std::sqrt((latitudeDistance * latitudeDistance) + (longitudeDistance * longitudeDistance));
}

Point::Point(double latitude, double longitude)
{
    this->latitude = latitude;
    this->longitude = longitude;
    this->planet = &earth;
    this->precision = std::stod(MIN_DISTANCE);
}

Point::~Point()
{
}
