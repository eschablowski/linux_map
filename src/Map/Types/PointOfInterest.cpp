#include "PointOfInterest.h"
#include "Map.h"
#include <SQLiteCpp/SQLiteCpp.h>

PointOfInterest::PointOfInterest(int id, Map *map)
{
    SQLite::Statement query = map->runQuery("SELECT address, name, type, website FROM Points_of_Interest WHERE id=:id LIMIT 1");
    query.bind(":id", id);
    query.executeStep();
    this->id = id;
    this->address = query.getColumn("address").getInt();
    this->name    = query.getColumn("name").getString();
    this->type    = query.getColumn("type").getString();
    this->website = query.getColumn("website").getString();
}

const Address PointOfInterest::getAddress() const
{
    Address address(this->address);
    return address;
}