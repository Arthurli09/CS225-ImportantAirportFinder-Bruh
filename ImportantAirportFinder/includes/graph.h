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
#include <math.h>
#include <limits>
#include <iostream>


#include "readFile.h"
using namespace std;

class Graph {
public:
    Graph() = default;
    Graph(vector<Airport> airports, vector<Edge> routes);
    
    void addEdge(Edge route);
    vector<string> getVertices();
    vector<string> getShortestPathWeighted(const string &source, const string &dest);
    vector<string> getShortestPathUnweighted(const string &source, const string &dest);
    // add vertex
    void addVertex(const string &vertex);
    // add edge and set weight based on the distance
    void addEdge(const string &source, const string &dest, double distance);
private:
    vector<string> vertices_;
    vector<Airport> all_airports;
    unordered_map<string,vector<pair<string, double>>> adjList;
    double calDistance(double lat1, double lat2, double long1, double long2);
};

// bool operator< (pair<string, int> a, pair<string, int> b) {
//     if (a.second < b.second) {
//         return true;
//     }
//     return false;
// }
