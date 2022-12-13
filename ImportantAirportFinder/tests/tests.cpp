#include "catch.hpp"

#include <algorithm>
#include <utility>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include "readFile.h"
#include "graph.h"

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
    string routeFile = "lib/dataSet/routes.dat";
    vector<Edge> routes = readRoute(routeFile);
    REQUIRE(routes.size() == 67240);
}

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

TEST_CASE("Testing getMostImportantAirport unweighted #1", "[part=2]") {
    string country = "Country A";
    string airportFile = "lib/testSet/testBetweenness.dat";
    string routeFile = "lib/testSet/testBetweenness2.dat";

    vector<Airport> test = readAirport(airportFile, country);
    vector<Edge> routes = readRoute(routeFile);
    Graph graph = Graph(country, airportFile, routeFile);

    REQUIRE(graph.getMostImportantAirport() == "Airport 02");
}

TEST_CASE("Testing getMostImportantAirport unweighted #2", "[part=2]") {
    string country = "Country B";
    string airportFile = "lib/testSet/testBetweenness.dat";
    string routeFile = "lib/testSet/testBetweenness2.dat";

    vector<Airport> test = readAirport(airportFile, country);
    vector<Edge> routes = readRoute(routeFile);
    Graph graph = Graph(country, airportFile, routeFile);

    REQUIRE(graph.getMostImportantAirport() == "Airport 06");
}

TEST_CASE("Testing getMostImportantAirport weighted #1", "[part=2]") {
    string country = "Country A";
    string airportFile = "lib/testSet/testBetweenness.dat";
    string routeFile = "lib/testSet/testBetweenness2.dat";

    vector<Airport> test = readAirport(airportFile, country);
    vector<Edge> routes = readRoute(routeFile);
    Graph graph = Graph(country, airportFile, routeFile);

    REQUIRE(graph.getMostImportantAirport(0.3, 0.7) == "Airport 02");
}

TEST_CASE("Testing getMostImportantAirport weighted #2", "[part=2]") {
    string country = "Country B";
    string airportFile = "lib/testSet/testBetweenness.dat";
    string routeFile = "lib/testSet/testBetweenness2.dat";

    vector<Airport> test = readAirport(airportFile, country);
    vector<Edge> routes = readRoute(routeFile);
    Graph graph = Graph(country, airportFile, routeFile);

    REQUIRE(graph.getMostImportantAirport(0.3, 0.7) == "Airport 06");
}

TEST_CASE("Testing calcBetweennessCentrality unweighted #1", "[part=2]") {
    Graph g = Graph();
    g.addVertex("A");
    g.addVertex("B");
    g.addVertex("C");
    g.addVertex("D");
    g.addVertex("E");

    g.addEdge("A", "B", 5);
    g.addEdge("A", "C", 2);
    g.addEdge("B", "D", 1);
    g.addEdge("B", "E", 6);

    g.calcBetweennessCentrality();
    REQUIRE(g.bt_map["B"] == 18);
}

TEST_CASE("Testing calcBetweennessCentrality unweighted #2", "[part=2]") {
    Graph g = Graph();
    g.addVertex("A");
    g.addVertex("B");
    g.addVertex("C");
    g.addVertex("D");
    g.addVertex("E");

    g.addEdge("A", "B", 5);
    g.addEdge("A", "C", 2);
    g.addEdge("B", "D", 1);
    g.addEdge("B", "E", 6);

    g.calcBetweennessCentrality();
    REQUIRE(g.bt_map["A"] == 14);
}

TEST_CASE("Testing calcBetweennessCentrality weighted #1", "[part=2]") {
    Graph g = Graph();
    g.addVertex("A");
    g.addVertex("B");
    g.addVertex("C");
    g.addVertex("D");
    g.addVertex("E");

    g.addEdge("A", "B", 5);
    g.addEdge("A", "C", 2);
    g.addEdge("B", "D", 1);
    g.addEdge("B", "E", 6);

    g.calcBetweennessCentrality(0.3, 0.7);
    REQUIRE(g.bt_map["B"] == 9);
}

TEST_CASE("Testing calcBetweennessCentrality weighted #2", "[part=2]") {
    Graph g = Graph();
    g.addVertex("A");
    g.addVertex("B");
    g.addVertex("C");
    g.addVertex("D");
    g.addVertex("E");

    g.addEdge("A", "B", 5);
    g.addEdge("A", "C", 2);
    g.addEdge("B", "D", 1);
    g.addEdge("B", "E", 6);

    g.calcBetweennessCentrality(0.3, 0.7);
    REQUIRE(g.bt_map["A"] == 7);
}