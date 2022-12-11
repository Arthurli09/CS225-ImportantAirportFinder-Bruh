#include "catch.hpp"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include "readFile.h"
#include "graph.h"

TEST_CASE("Testing weird input", "[part=1]") {
    string country = "Germany";
    string airportFile = "lib/testSet/testAirport.dat";
    vector<Airport> GermanyAirports = readAirport(airportFile, country);
    REQUIRE(GermanyAirports.size() == 333);
    REQUIRE(GermanyAirports[332].name == "Magdeburg \"City\" Airport");
}

TEST_CASE("Testing reading airports (in Greece)", "[part=1]") {
    string country = "Greece";
    string airportFile = "lib/dataSet/airports.dat";
    vector<Airport> GreeceAirports = readAirport(airportFile, country);
    REQUIRE(GreeceAirports.size() == 14111);
    REQUIRE(GreeceAirports[0].name == "");
    REQUIRE(GreeceAirports[1].id == "0");
    REQUIRE(GreeceAirports[1444].name == "Andravida Air Base");
    REQUIRE(GreeceAirports[1488].name == "Zakynthos International Airport \"Dionysios Solomos\"");
    REQUIRE(GreeceAirports[6887].latitude == 37.297501);
}

TEST_CASE("Testing reading routes", "[part=1]") {
    string routeFile = "lib/dataSet/routes.dat";
    vector<Edge> routes = readRoute(routeFile);
    REQUIRE(routes.size() == 67240);
}

TEST_CASE("Testing Dijkstra #1", "[part=1]") {
    Graph g = Graph();
    g.addVertex("A");
    g.addVertex("B");
    g.addVertex("C");
    g.addVertex("D");
    g.addVertex("E");
    g.addVertex("F");
    g.addVertex("G");

    g.addEdge("A", "B", 5);
    g.addEdge("A", "C", 2);
    g.addEdge("B", "D", 1);
    g.addEdge("B", "E", 6);
    g.addEdge("C", "D", 6);
    g.addEdge("C", "F", 8);
    g.addEdge("D", "E", 1);
    g.addEdge("D", "F", 2);
    g.addEdge("E", "G", 7);
    g.addEdge("F", "G", 3);

    std::string path_s = "";
    vector<string> path = g.getShortestPathWeighted("A", "G");
    for (auto &i : path) {
      path_s += i;
    }
    REQUIRE(path_s == "ABDFG");
}

TEST_CASE("Testing Dijkstra #2", "[part=1]") {
    Graph g = Graph();
    g.addVertex("A");
    g.addVertex("B");
    g.addVertex("C");
    g.addVertex("D");
    g.addVertex("E");
    g.addVertex("F");
    g.addVertex("G");

    g.addEdge("A", "B", 5);
    g.addEdge("A", "C", 2);
    g.addEdge("B", "D", 1);
    g.addEdge("B", "E", 6);
    g.addEdge("C", "D", 6);
    g.addEdge("C", "F", 8);
    g.addEdge("D", "E", 1);
    g.addEdge("D", "F", 2);
    g.addEdge("E", "G", 7);
    g.addEdge("F", "G", 3);

    std::string path_s = "";
    vector<string> path = g.getShortestPathWeighted("A", "F");
    for (auto &i : path) {
      path_s += i;
    }
    REQUIRE(path_s == "ABDF");
}

TEST_CASE("Testing Dijkstra #3", "[part=1]") {
    Graph g = Graph();
    g.addVertex("A");
    g.addVertex("B");
    g.addVertex("C");
    g.addVertex("D");
    g.addVertex("E");
    g.addVertex("F");
    g.addVertex("G");

    g.addEdge("A", "B", 5);
    g.addEdge("A", "C", 2);
    g.addEdge("B", "D", 1);
    g.addEdge("B", "E", 6);
    g.addEdge("C", "D", 6);
    g.addEdge("C", "F", 8);
    g.addEdge("D", "E", 1);
    g.addEdge("D", "F", 2);
    g.addEdge("E", "G", 7);
    g.addEdge("F", "G", 3);

    std::string path_s = "";
    vector<string> path = g.getShortestPathWeighted("A", "B");
    for (auto &i : path) {
      path_s += i;
    }
    REQUIRE(path_s == "AB");
}

TEST_CASE("Testing BFS #1", "[part=1]") {
    Graph g = Graph();
    g.addVertex("A");
    g.addVertex("B");
    g.addVertex("C");
    g.addVertex("D");
    g.addVertex("E");
    g.addVertex("F");
    g.addVertex("G");

    g.addEdge("A", "B", 5);
    g.addEdge("A", "C", 2);
    g.addEdge("B", "D", 1);
    g.addEdge("B", "E", 6);
    g.addEdge("C", "D", 6);
    g.addEdge("C", "F", 8);
    g.addEdge("D", "E", 1);
    g.addEdge("D", "F", 2);
    g.addEdge("E", "G", 7);
    g.addEdge("F", "G", 3);

    std::string path_s = "";
    vector<string> path = g.getShortestPathUnweighted("A", "G");
    for (auto &i : path) {
      path_s += i;
    }
    REQUIRE(path_s == "ABEG");
}

TEST_CASE("Testing BFS #2", "[part=1]") {
    Graph g = Graph();
    g.addVertex("A");
    g.addVertex("B");
    g.addVertex("C");
    g.addVertex("D");
    g.addVertex("E");
    g.addVertex("F");
    g.addVertex("G");

    g.addEdge("A", "B", 5);
    g.addEdge("A", "C", 2);
    g.addEdge("B", "D", 1);
    g.addEdge("B", "E", 6);
    g.addEdge("C", "D", 6);
    g.addEdge("C", "F", 8);
    g.addEdge("D", "E", 1);
    g.addEdge("D", "F", 2);
    g.addEdge("E", "G", 7);
    g.addEdge("F", "G", 3);

    std::string path_s = "";
    vector<string> path = g.getShortestPathUnweighted("A", "F");
    for (auto &i : path) {
      path_s += i;
    }
    REQUIRE(path_s == "ACF");
}

TEST_CASE("Testing BFS #3", "[part=1]") {
    Graph g = Graph();
    g.addVertex("A");
    g.addVertex("B");
    g.addVertex("C");
    g.addVertex("D");
    g.addVertex("E");
    g.addVertex("F");
    g.addVertex("G");

    g.addEdge("A", "B", 5);
    g.addEdge("A", "C", 2);
    g.addEdge("B", "D", 1);
    g.addEdge("B", "E", 6);
    g.addEdge("C", "D", 6);
    g.addEdge("C", "F", 8);
    g.addEdge("D", "E", 1);
    g.addEdge("D", "F", 2);
    g.addEdge("E", "G", 7);
    g.addEdge("F", "G", 3);

    std::string path_s = "";
    vector<string> path = g.getShortestPathUnweighted("A", "E");
    for (auto &i : path) {
      path_s += i;
    }
    REQUIRE(path_s == "ABE");
}