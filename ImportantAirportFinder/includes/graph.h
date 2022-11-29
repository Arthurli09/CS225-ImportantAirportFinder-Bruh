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


#include "readFile.h"
using namespace std;

class Graph {
public:
    Graph(vector<Airport> airports, vector<Edge> routes);
    void addEdge(string source, string dest);
    vector<string> getVertices();
private:
    vector<string> airportIDs;
    unordered_map<string,vector<string>> adjList;
};
