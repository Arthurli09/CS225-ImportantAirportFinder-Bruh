#include "catch.hpp"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include "readFile.h"
#include "graph.h"

TEST_CASE("Testing input with double quotation marks", "[part=1]") {
    string country = "Germany";
    string airportFile = "lib/testSet/testAirport.dat";
    vector<Airport> GermanyAirports = readAirport(airportFile, country);
    REQUIRE(GermanyAirports.size() == 333);
    REQUIRE(GermanyAirports[332].name == "Magdeburg \"City\" Airport");
}

TEST_CASE("Testing input with commas", "[part=1]") {
    string country = "Germany";
    string airportFile = "lib/testSet/testAirport2.dat";
    vector<Airport> GermanyAirports = readAirport(airportFile, country);
    REQUIRE(GermanyAirports.size() == 333);
    REQUIRE(GermanyAirports[332].name == "This, is, cringe");
    REQUIRE(GermanyAirports[1].id == "0");
    REQUIRE(GermanyAirports[317].latitude == 51.193611);
    REQUIRE(GermanyAirports[317].longitude == 14.519722);
}

TEST_CASE("Testing routes with null id", "[part=1]") {
    string routeFile = "lib/dataSet/routes.dat";
    string testRoute = "lib/testSet/testRoute.dat";
    vector<Edge> routes = readRoute(routeFile);
    vector<Edge> routes2 = readRoute(testRoute);
    REQUIRE(routes2.size() == 0);
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