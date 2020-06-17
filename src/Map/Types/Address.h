#include <string>
#include "Street.h"
#include "Map.h"

#pragma once

class Address
{
public:
    Address(int id, Map *map);
    const Street getStreet() const;
    int houseNumber;
    std::string country;
    std::string state;
    std::string postalCode;
    double latitude;
    double longitude;
private:
    int id;
    int street;
};
