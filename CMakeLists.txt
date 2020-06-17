# Copyright (c) 2014-2016, Ruslan Baratov
# All rights reserved.

cmake_minimum_required(VERSION 3.2)

set (CMAKE_CXX_STANDARD 11)

### Hunter snapshot that will be used ###
include("cmake/HunterGate.cmake")
HunterGate(
    URL "https://github.com/ruslo/hunter/archive/v0.23.111.tar.gz"
    SHA1 "4189bbd869abe4eb69b5303d3f916c03d34dc154"
)

project("CS20A_Project_4_SQLite" VERSION 1.0)

set(MIN_DISTANCE "0.5" CACHE STRING "Distance to detect two points as equal (in meters)")
set(COMPRESSION "5" CACHE STRING "How many times to mutiply MIN_DISTANCE to achive a map (lower gives a better resolution, but bigger database)")

file(READ src/Database/Create.sql CREATE_COMMAND)
string(REPLACE "
"
       "" CREATE_COMMAND ${CREATE_COMMAND})


hunter_add_package(sqlite3)
find_package(sqlite3 CONFIG REQUIRED)
hunter_add_package(libxml2)
find_package(LibXml2 REQUIRED)
hunter_add_package(cxxopts)
find_package(cxxopts CONFIG REQUIRED)

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/external/SQLiteCpp)

include_directories(
  ${CMAKE_CURRENT_LIST_DIR}/external/SQLiteCpp/include
)

configure_file(src/config.h.in config.h ESCAPE_QUOTES)
set(MAP_Sources src/Map/Map.h src/Map/Connection.h src/Map/Globe.hpp src/Map/Path.h src/Map/Point.cpp src/Map/Point.h)
set(XMLReader_Sources src/xmlImporter/XMLReader.h src/xmlImporter/XMLReader.h)
set(DB_SOURCES src/Database/Database.h)

include_directories(src)
include_directories(${CMAKE_CURRENT_BINARY_DIR})
add_executable(map src/main.cpp ${MAP_Sources})
target_link_libraries(map PRIVATE LibXml2::LibXml2 sqlite3::sqlite3 cxxopts::cxxopts SQLiteCpp)
