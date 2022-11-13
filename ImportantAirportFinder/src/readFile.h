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
};

vector<Airport> readFile(string file);