#include <string>
#include <vector>
#include <SQLiteCpp/SQLiteCpp.h>
#include "Point.h"

class Map {
private:
    SQLite::Database db;
public:
    Map(std::string db);
    ~Map();
    std::vector<Point> getPointOfInterest(std::string query);
    Point getClosestPoint(double latitude, double longitude);
    SQLite::Statement runQuery(std::string query);
};
