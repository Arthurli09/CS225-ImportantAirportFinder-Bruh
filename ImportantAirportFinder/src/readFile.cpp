#include "readFile.h"

vector<Airport> readAirport(string dataLocation, string country) {
    vector<Airport> airports;
    Airport holder = Airport{"0", "", "", 0, 0, 0};
    airports.push_back(holder);
    ifstream file;
    /*
        If you are in the ImportantAirportFinder directory already,
        use ./lib/dataSet/airports.dat instead
    */
    file.open(dataLocation);
    if (file.is_open()) {
        string line;
        int count = 1;
        while (getline(file, line)) {
            Airport a;
            string curID;
            string curName;
            string curCountry;
            double latitude;
            double longitude;
            int numID;
            size_t pos;
            // getID
            curID = line.substr(0, line.find(","));
            line = line.substr(line.find(",") + 1);
            // getName
            pos = getCorrectPos(line);
            curName = line.substr(0, line.find(",", pos));
            curName = formatString(curName);
            line = line.substr(line.find(",", pos) + 1);
            // Skip
            pos = getCorrectPos(line);
            line = line.substr(line.find(",", pos) + 1);
            // getCountry
            curCountry = line.substr(0, line.find(","));
            curCountry = formatString(curCountry);
            line = line.substr(line.find(",") + 1);
            // Skip
            line = line.substr(line.find(",") + 1);
            line = line.substr(line.find(",") + 1);
            // getLatitude
            latitude = stod(line.substr(0, line.find(",")));
            line = line.substr(line.find(",") + 1);
            // getLongitude
            longitude = stod(line.substr(0, line.find(",")));
            numID = stoi(curID);
            if (numID > count) {
                for (; count < numID; count++) {
                    airports.push_back(holder);
                }
            }
            if (curCountry != country) {
                a = Airport{"0", "", "", latitude, longitude, 0};
                airports.push_back(a);
            } else {
                a = Airport{curID, curName, curCountry, latitude, longitude, 0};
                airports.push_back(a);
            }
            count++;
        }
    } else {
        throw runtime_error("Could not open file.");
    }
    return airports;
}

vector<Edge> readRoute(string dataLocation) {
    vector<Edge> routes;
    ifstream file;
    file.open(dataLocation);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            Edge e;
            string source;
            string dest;
            // Get variable
            line = line.substr(line.find(",") + 1);
            line = line.substr(line.find(",") + 1);
            line = line.substr(line.find(",") + 1);

            source = line.substr(0, line.find(","));
            line = line.substr(line.find(",") + 1);
            line = line.substr(line.find(",") + 1);
            dest = line.substr(0, line.find(","));
            // Push
            if (source != "\\N" && dest != "\\N") {
                e = Edge{source, dest};
                routes.push_back(e);
            }
        }
    } else {
        throw runtime_error("Could not open file.");
    }
    return routes;
}

string formatString(string str) {
    if (str.length() >= 3) {
        str = str.substr(1, str.length() - 2);
        size_t pos = str.find("\"\"");
        while (pos != string::npos) {
            str.replace(pos, 2, "\"");
            pos++;
            pos = str.find("\"\"", pos);
        }
    }
    return str;
}

size_t getCorrectPos(string str) {
    size_t pos = 0;
    while (str.find(",", pos) < str.find("\"", 1)) {
        pos = str.find(",", pos) + 1;
    }
    return pos;
}