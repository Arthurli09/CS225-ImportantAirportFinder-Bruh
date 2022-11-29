#include "includes/graph.h"

using namespace std;

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

set<string> Graph::getShortestPath(string source, string dest) {
    set<string> path;
    set<string> visited;
    priority_queue<pair<string, int>> queue;
    map<string, string> previous;

    for(string airport : vertices_) {
        pair<string, int> pair;
        pair.first = airport;
        pair.second = 2147483647;
        if (airport == source) {
            pair.second = 0;
        }
    } 

    while(queue.top().first != dest) {
        string current_airport = queue.top().first;
        vector<string> neighbours = adjList[current_airport];
        for(string neighbour : neighbours) {
            if (visited.count(neighbour) > 0) {
                continue;
            }
            visited.insert(neighbour);
            previous[neighbour] = current_airport;
        }
    }   

    return path;
}


