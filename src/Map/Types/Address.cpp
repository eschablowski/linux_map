#include "Address.h"
#include "Map.h"
#include <SQLiteCpp/SQLiteCpp.h>

Address::Address(int id, Map *map)
{
    SQLite::Statement query = map->runQuery("SELECT street, house_number, country, state, postal_code, latitude, longitude FROM Addresses WHERE id=:id LIMIT 1");
    query.bind(":id", id);
    query.executeStep();
    this->id = id;
    this->street      = query.getColumn("street").getInt();
    this->houseNumber = query.getColumn("house_number").getInt();
    this->state       = query.getColumn("state").getString();
    this->postalCode  = query.getColumn("postal_code").getString();
    this->latitude    = query.getColumn("street").getInt();
    this->longitude   = query.getColumn("house_number").getInt();
}

const Street Address::getStreet() const
{
    Street street(this->address);
    return street;
}