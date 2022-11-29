#pragma once

#include <vector>
#include <fstream>
#include <exception>

using namespace std;

struct Airport {
    string id;
    string name;
    string city;
    string country;
    string IATA;
    string ICAO;
    int betweeness;
};

struct Edge {
    string source;
    string dest;
};

vector<Airport> readAirport(string dataLocation, string country);
vector<Edge> readRoute(string dataLocation, string country);
string formatString(string str);