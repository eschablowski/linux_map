#include "Point.h"

class Path {
private:
    double distance;
    Point *a;
    Point *b;
    PathSection *head;
public:
    Path(Point startingPoint);
    virtual ~Path();
    void addPoint(Point *point);
    void simplifyPath();
    Point *getPoints();
};

struct PathSection {
    Point *point;
    double distance;
    Point *next;
    bool turn;
};