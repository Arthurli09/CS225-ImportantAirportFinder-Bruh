#include "graph.h"

Graph::Graph(vector<Airport> airports, vector<Edge> routes) {
    for (auto airport : airports) {
        airportIDs.push_back(airport.id);
    }
    for (auto route : routes) {
        adjList[route.source].push_back(route.dest);
    }
}

void Graph:: addEdge(string source, string dest) {
    adjList[source].push_back(dest);
}

vector<string> Graph::getVertices() {
    return airportIDs;
}