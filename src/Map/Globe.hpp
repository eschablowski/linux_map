#include "config.h"
#include <string>
#include <cmath>

#pragma once

class Planet
{
protected:
    /**
     * The planet radius, currently unused
     * unit: Meters
     */
    double radius;
    /**
     * The radius around the planet around the equator
     * unit: Meters
     */
    double circumferenceEquatorial;
    /**
     * The radius around the planet around the meridian
     * unit: Meters
     */
    double circumferenceMeridional;
    /**
     * The distance to earth on the X axis, whatever that is going to mean...
     * unit: Lightyears
     */
    double distanceToEarthX;
    /**
     * The distance to earth on the Y axis, whatever that is going to mean...
     * unit: Lightyears
     */
    double distanceToEarthY;
    /**
     * Compares two doubles with an epsilon, to make sure math rounding does not affect us
     */
    static const bool compareEpsilon(const double a, const double b, const double epsilon)
    {
        return std::abs(a - b) < epsilon;
    }

public:
    Planet(double radius, double circumferenceEquatorial, double circumferenceMeridional, long distanceToEarthX, long distanceToEarthY);
    virtual const bool compareLatitude(double latitude1, double latitude2, double precision = std::stod(MIN_DISTANCE)) const
    {
        const double latitudeEpsilon = 180.0 * precision / this->circumferenceMeridional;
        return compareEpsilon(latitude1, latitude2, latitudeEpsilon);
    }
    virtual const bool compareLongitude(double latitude1, double latitude2, double precision = std::stod(MIN_DISTANCE)) const
    {
        const double longitudeEpsilon = 180.0 * precision / this->circumferenceEquatorial;
        return compareEpsilon(latitude1, latitude2, longitudeEpsilon);
    }
    friend double distance(Planet& planet1, Planet& planet2);
};

const Planet earth(
    /* 6371 km Mean Earth Radius (https://en.wikipedia.org/wiki/Earth) */ 6.371e6,
    /* 40075.017 km Equatorial Earth Radius*/ 40075.017e3,
    /* 40007.86 km Meridional Equatorial Earth Radius*/ 40007.86e3,
    /* This is earth, so somewhat useless */ 0,
    /* This is earth, so somewhat useless */ 0);


double distance(Planet &planet1, Planet &planet2)
{
    const double xDistance = planet1.distanceToEarthX - planet2.distanceToEarthX;
    const double yDistance = planet1.distanceToEarthY - planet2.distanceToEarthY;
    return std::sqrt((xDistance * xDistance) + (yDistance * yDistance));
}