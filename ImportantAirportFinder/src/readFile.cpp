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
        while (getline(file, line)) {
            Airport a;
            string curID;
            string curName;
            string curCountry;
            double latitude;
            double longitude;
            // getID
            curID = line.substr(0, line.find(","));
            line = line.substr(line.find(",") + 1);
            // getName
            curName = line.substr(0, line.find(","));
            curName = formatString(curName);
            line = line.substr(line.find(",") + 1);
            // Skip
            line = line.substr(line.find(",") + 1);
            // getCountry
            curCountry = line.substr(0, line.find(","));
            curCountry = formatString(curCountry);
            if (curCountry != country) {
                a = Airport{"0", "", "", 0, 0, 0};
                airports.push_back(a);  
                continue;
            }
            line = line.substr(line.find(",") + 1);
            // Skip
            line = line.substr(line.find(",") + 1);
            line = line.substr(line.find(",") + 1);
            // getLatitude
            latitude = stod(line.substr(0, line.find(",")));
            line = line.substr(line.find(",") + 1);
            // getLongitude
            longitude = stod(line.substr(0, line.find(",")));
            a = Airport{curID, curName, curCountry, latitude, longitude, 0};
            airports.push_back(a);
        }
    } else {
        throw runtime_error("Could not open file.");
    }
    return airports;
}

vector<Edge> readRoute(string dataLocation, string country) {
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