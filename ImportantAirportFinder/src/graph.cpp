#include "graph.h"

Graph::Graph(vector<Airport> airports, vector<Edge> routes) {
    for (auto airport : airports) {
        vertices_.push_back(airport.id);
        all_airports.push_back(airport);
    }
    for (auto route : routes) {
        addEdge(route);
    }
}

void Graph::addEdge(Edge route) {    // add edge and set weight based on the distance
    double lat1 = all_airports[stoi(route.source)].latitude;
    double long1 = all_airports[stoi(route.source)].longitude;
    double lat2 = all_airports[stoi(route.dest)].latitude;
    double long2 = all_airports[stoi(route.dest)].longitude;
    route.weight = calDistance(lat1, lat2, long1, long2);
    adjList[route.source].push_back(pair<string, double>(route.source, route.weight));
}

double Graph::calDistance(double lat1, double lat2, double long1, double long2) {
    double dlat = ((M_PI) / 180 * lat2) - ((M_PI) / 180 * lat1);
    double dlong = ((M_PI) / 180 * long2) - ((M_PI) / 180 * long1);
    double result = pow(sin(dlat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(dlong / 2), 2);
    result = 2 * asin(sqrt(result));
    result *= 6371.0;
    return result;
}

vector<string> Graph::getVertices() {
    return vertices_;
}