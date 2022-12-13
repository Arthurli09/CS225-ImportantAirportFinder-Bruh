#include "readFile.h"
#include "graph.h"
#include <iostream>

using namespace std;

/*
    Note: This is an early stage temporary compilation method, it is recommended to use Makefile
          to compile.
    
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

/*
    User guide for using the MostImportantAirportFinder:
        1. Specify the country for searching the most important airport in.
            a. Change the string behind the "country" variable.

        2. Specify the airport file and route file as datasets for the algorithm.
            a. Change the string behind the "airportFile" variable and the "routeFile" variable.

        3-1. If planning to use the default getMostImportantAirportFinder function
             (where the weights are 0.5, 0.5), use getMostImportantAirport().

        3-2. If planning to use the weighted getMostImportantAirportFinder function
             (where the weights are specified in the parameter), add weights in the
             getMostImportantAirport() funtion
             (i.e. use getMostImportantAirport(double dijkstraWeight, double bfsWeight)).

        PS: Explanation of the weights:
            Betweennes centrality for an airport is based on how many times an airport in
            a specified country appears on the shortest paths between all the unique pairs
            of airports in that country. It determines the importance of an airport in this
            algorithm.

            Betweennes centrality, and therefore the importance of an airport in this algorithm,
            can be determined based on two methods:
            1) The number of times an airport in a specified country appears on the paths with
            the shortest DISTANCE (using Dijkstra) between all the unique pairs of airports
            in that country.
            2) The number of times an airport in a specified country appears on the paths with
            the least number of TRANSFERS/TRANSIT FLIGHTS (using BFS) between all the unique pairs of airports
            in that country.

            The weights specify how much of shortest distance (Dijkstra) a user cares about
            and how much of least number of transfers/transit flights (BFS) a user cares about
            when finding the most important airport in a specified country.

            The first weight is for shortest distance (Dijkstra), the second weight is for
            least number of transfers/transit flights (BFS).

            The weights must add up to 1 (e.g. 0.3, 0.7). For instance, if a user only cares about
            shortest distance when finding the most important airport, the user can enter (1, 0)
            in the parameter of the getMostImportantAirport() function.
*/

int main() {
    string country = "Russia";
    string airportFile = "lib/dataSet/airports.dat";
    string routeFile = "lib/dataSet/routes.dat";

    Graph graph = Graph(country, airportFile, routeFile);

    string mostImportantAirport = graph.getMostImportantAirport();

    cout << "The most important airport in " << country << " is: " << mostImportantAirport << "." << endl;

    return 0;
}