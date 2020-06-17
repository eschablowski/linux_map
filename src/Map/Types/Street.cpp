#include "Street.h"
#include "Map.h"
#include <SQLiteCpp/SQLiteCpp.h>

Street::Street(int id, Map *map)
{
    SQLite::Statement query = map->runQuery("SELECT name FROM Streets WHERE id=:id LIMIT 1");
    query.bind(":id", id);
    query.executeStep();
    this->id = id;
    this->name = query.getColumn("name").getString();
}

