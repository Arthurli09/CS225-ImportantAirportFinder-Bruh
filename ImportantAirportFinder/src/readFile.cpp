#include "readFile.h"

vector<Airport> readAirport(string dataLocation, string country) {
    vector<Airport> airports;
    Airport holder = Airport{"0", "", "", "", "", ""};
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
            string curCity;
            string curCountry;
            string curIATA;
            string curICAO;
            curID = line.substr(0, line.find(","));
            line = line.substr(line.find(",") + 1);
            curName = line.substr(0, line.find(","));
            curName = formatString(curName);
            line = line.substr(line.find(",") + 1);
            curCity = line.substr(0, line.find(","));
            curCity = formatString(curCity);
            line = line.substr(line.find(",") + 1);
            curCountry = line.substr(0, line.find(","));
            curCountry = formatString(curCountry);
            if (curCountry != country) {
                a = Airport{"0", "", "", "", "", ""};
                airports.push_back(a);  
                continue;
            }
            line = line.substr(line.find(",") + 1);
            curIATA = line.substr(0, line.find(","));
            curIATA = formatString(curIATA);
            line = line.substr(line.find(",") + 1);
            curICAO = line.substr(0, line.find(","));
            curICAO = formatString(curICAO);
            a = Airport{curID, curName, curCity, curCountry, curIATA, curICAO};
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