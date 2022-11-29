#pragma once

#include <list>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <climits>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <set>
#include <sstream>
#include <vector>
#include <queue>
#include <map>


#include "readFile.h"
using namespace std;

class Graph {
public:
    Graph(vector<Airport> airports, vector<Edge> routes);
    void addEdge(string source, string dest);
    vector<string> getVertices();
    set<string> getShortestPath(string source, string dest);
    
private:
    vector<string> airportIDs;
    unordered_map<string,vector<string>> adjList;
};

bool operator< (pair<string, int> a, pair<string, int> b) {
    if (a.second < b.second) {
        return true;
    }
    return false;
}
