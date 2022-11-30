#include "catch.hpp"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include "readFile.h"
#include "graph.h"

TEST_CASE("Testing test case", "[part=1]") {
    int a = 1;
    int b = 1;
    REQUIRE(a == b);
}

TEST_CASE("Testing reading airports (in Greece)", "[part=1]") {
    string country = "Greece";
    string airportFile = "lib/dataSet/airports.dat";
    vector<Airport> GreeceAirports = readAirport(airportFile, country);
    REQUIRE(GreeceAirports.size() == 9357);
    REQUIRE(GreeceAirports[0].name == "");
    REQUIRE(GreeceAirports[1].id == "0");
    REQUIRE(GreeceAirports[1444].name == "Andravida Air Base");
    REQUIRE(GreeceAirports[1488].name == "Zakynthos International Airport \"Dionysios Solomos\"");
    REQUIRE(GreeceAirports[6887].latitude == 37.297501);
}

TEST_CASE("Testing reading routes", "[part=1]") {
    string country = "Greece";
    string routeFile = "lib/dataSet/routes.dat";
    vector<Edge> routes = readRoute(routeFile, country);
    REQUIRE(routes.size() == 67240);
}