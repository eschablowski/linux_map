#include "Map.h"

Map::Map(std::string name): db(name)
{
}

Point *Map::getPointOfInterest(std::string query)
{
    SQLite::Statement   dbQuery(this->db, "SELECT address, name");
}
