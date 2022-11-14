
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

#include "edge.h"
#include "readFile.h"

class Graph
{
public:
    // Create an empty unweighted directed graph.
    Graph();

    // get adjacent airports and edge.
    vector<Vertex> getAdjacent(Vertex source) const;
    Edge getEdge(Vertex source, Vertex destination) const;

    // Checks
    bool vertexExists (Vertex v) const;
    bool edgeExists(Vertex source, Vertex destination) const;

    // Inserts
    void insertVertex(Vertex v);
    bool insertEdge(Vertex source, Vertex destination);
    
    // Remove all the data
    void clear();
    
    // Helper functions
    bool assertassertEdgeExists(Vertex source, Vertex destination, string functionName) const;
    bool assertVertexExists(Vertex v, string functionName) const;
    // Remove
    Edge removeEdge(Vertex source, Vertex destination);
    Vertex removeVertex(Vertex v);

private:
    mutable unordered_map<Vertex, unordered_map<Vertex, Edge>> adjacency_list;
};
