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
#include <math.h>


#include "readFile.h"
using namespace std;

class Graph {
public:
    Graph(vector<Airport> airports, vector<Edge> routes);
    void addEdge(Edge route);
    vector<string> getVertices();
private:
    vector<string> vertices_;
    vector<Airport> all_airports;
    unordered_map<string,vector<pair<string, double>>> adjList;
    double calDistance(double lat1, double lat2, double long1, double long2);
};
