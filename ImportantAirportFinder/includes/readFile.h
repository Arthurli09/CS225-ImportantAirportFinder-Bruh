#pragma once

#include <vector>
#include <fstream>
#include <exception>
#include <iostream>

using namespace std;

struct Airport {
    string id;
    string name;
    string country;
    double latitude;
    double longitude;
    int betweeness;
};

struct Edge {
    string source;
    string dest;
    double weight;
};

vector<Airport> readAirport(string dataLocation, string country);
vector<Edge> readRoute(string dataLocation, string country);
string formatString(string str);