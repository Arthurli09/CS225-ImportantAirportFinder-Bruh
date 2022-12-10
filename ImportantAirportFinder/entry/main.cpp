#include "readFile.h"
#include "graph.h"
#include <iostream>

using namespace std;

/*
    To compile, use one of the two ways:

    Way #1 (tested): make sure the current directory is the directory that includes all of the files
    (e.g. .devcontainer, ImportantAirportFinder, etc.). Then, run the command:
        clang++ -std=c++2a -g -O0 -I ./ImportantAirportFinder/src -o ./ImportantAirportFinder/bin/exec
        ./ImportantAirportFinder/src/readFile.cpp ./ImportantAirportFinder/entry/main.cpp
    Then, run the command: ./ImportantAirportFinder/bin/exec
    To remove all files in bin, run: rm -fr ./ImportantAirportFinder/bin/(add an asterisk)

    Way #2 (untested): cd into the ImportantAirportFinder directory. Then, run the command:
        clang++ -std=c++2a -g -O0 -I ./src -o ./bin/exec ./src/readFile.cpp ./entry/main.cpp
    Then, run the command: ./bin/exec
    To remove all files in bin, run: rm -fr ./bin/(add an asterisk)

    PS: The bracket (add an asterisk) is to be replaced with an *, since directly typing an *
    in the command will generate an warning.
*/

int main() {
    string country = "United Kingdom";
    string airportFile = "lib/dataSet/airports.dat";
    string routeFile = "lib/dataSet/routes.dat";
    bool found = false;
    int order = 1;
    vector<Airport> test = readAirport(airportFile, country);
    vector<Edge> routes = readRoute(routeFile);
    Graph graph = Graph(test, routes);

    vector<string> vertices = graph.getVertices();
    for (unsigned int i = 0; i < 1200; i++) {
        cout << vertices[i] << endl;
    }

    /*for (auto edge : routes) {
        cout << edge.source << " -> " << edge.dest << endl;
    }*/

    /*for (unsigned int i = 0; i < test.size(); i++) {
        if (test[i].country == country) {
            cout << "The " << order << " st/nd/rd/th airport in " << country << " with ID: " << test[i].id <<
            " at " << i << " st/nd/rd/th position in the airports vector is: " << test[i].name <<
            " with latitude " << test[i].latitude << " and longitude: " << test[i].longitude << "." << endl;
            found = true;
            order++;
        }
    }
    if (!found) {
        cout << "No airport found with the given country." << endl;
    }*/

    /*vector<string> path = graph.getShortestPath("1444", "1455");

    for (string airport_id : path) {
        cout << airport_id << endl;
    }*/

    return 0;
}