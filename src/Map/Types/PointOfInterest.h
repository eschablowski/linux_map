#include <string>
#include "Address.h"
#include "Map.h"

#pragma once

class PointOfInterest
{
public:
    PointOfInterest(int id, Map *map);
    const Address getAddress() const;
    std::string name;
    std::string type;
    std::string website;
private:
    int id;
    int address;
};
