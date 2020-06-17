#include <string>
#include "StreetNode.h"
#include "Map.h"

#pragma once

class Street
{
public:
    Street(int id, Map *map);
    std::string name;

    // member typedefs provided through inheriting from std::iterator
    class iterator: public std::iterator<
                        std::input_iterator_tag,   // iterator_category
                        StreetNode,                      // value_type
                        StreetNode,                      // difference_type
                        const StreetNode*,               // pointer
                        StreetNode                       // reference
                                      >{
        SQLite::Statement sql;
    public:
        explicit iterator(int id, Map *map) : num(_num) {}
        iterator& operator++() {num = TO >= FROM ? num + 1: num - 1; return *this;}
        iterator operator++(int) {iterator retval = *this; ++(*this); return retval;}
        bool operator==(iterator other) const {return num == other.num;}
        bool operator!=(iterator other) const {return !(*this == other);}
        reference operator*() const {return num;}
    };
    iterator begin() {return iterator(FROM);}
    iterator end() {return iterator(TO >= FROM? TO+1 : TO-1);}
private:
    int id;
};
