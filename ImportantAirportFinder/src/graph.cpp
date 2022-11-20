#include "graph.h"

Graph::Graph(string airportFile, string routeFile, string country) {
    vector<Airport> airports;
    vector<Edge> routes;
    airports = readAirport(airportFile, country);
    routes = readRoute(routeFile, country);

    for (auto &airport: airports) {
        if (airport.id != "0") validAirports.push_back(airport.id);
    }

    for (auto &edge: routes) { 
        adjList[edge.source].push_back(edge.dest);
    }

}

void Graph::addEdge(string source, string dest) {
    adjList[source].push_back(dest);
}
