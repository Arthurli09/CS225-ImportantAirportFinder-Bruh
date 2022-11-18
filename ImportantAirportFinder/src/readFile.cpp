#include "readFile.h"

vector<Airport> readFile(string country) {
    vector<Airport> airports;
    Airport holder = Airport{"0", "", "", "", "", ""};
    airports.push_back(holder);
    ifstream file;
    /*
        If you are in the ImportantAirportFinder directory already,
        use ./lib/dataSet/airports.dat instead
    */
    file.open("./ImportantAirportFinder/lib/dataSet/airports.dat");
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
            line = line.substr(line.find("\"") + 1);
            curName = line.substr(0, line.find("\""));
            line = line.substr(line.find("\"") + 3);
            curCity = line.substr(0, line.find("\""));
            line = line.substr(line.find("\"") + 3);
            curCountry = line.substr(0, line.find("\""));
            if (curCountry != country) {
                a = Airport{"0", "", "", "", "", ""};
                airports.push_back(a);
                continue;
            }
            line = line.substr(line.find("\"") + 3);
            curIATA = line.substr(0, line.find("\""));
            line = line.substr(line.find("\"") + 3);
            curICAO = line.substr(0, line.find("\""));
            a = Airport{curID, curName, curCity, curCountry, curIATA, curICAO};
            airports.push_back(a);
        }
    } else {
        throw runtime_error("Could not open file.");
    }
    return airports;
}