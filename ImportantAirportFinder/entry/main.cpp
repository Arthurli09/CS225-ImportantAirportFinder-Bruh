#include "readFile.h"
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
    string country = "Papua New Guinea";
    bool found = false;
    vector<Airport> test = readFile(country);
    for (unsigned int i = 0; i < test.size(); i++) {
        if (test[i].id != "0") {
            cout << "The first airport in " << country << " is: " << test[i].name << "." << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "No airport found with the given country." << endl;
    }
    return 0;
}