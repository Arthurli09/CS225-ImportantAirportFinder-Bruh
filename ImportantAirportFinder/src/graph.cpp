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

set<string> Graph::getShortestPath(string source, string dest) {
    set<string> path;
    set<string> visited;
    priority_queue<pair<string, int>> queue;
    map<string, string> previous;

    for(string airport : airportIDs) {
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


