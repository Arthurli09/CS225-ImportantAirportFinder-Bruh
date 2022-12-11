#include "graph.h"

using namespace std;

Graph::Graph(vector<Airport> airports, vector<Edge> routes) {
    all_airports = airports;  
    for (auto route : routes) {
        //cout << route.source << endl;
        //cout << route.dest << endl;
        if (all_airports[stoi(route.source)].id != "0" || all_airports[stoi(route.dest)].id != "0") {
          addEdge(route);
          if (all_airports[stoi(route.source)].id == "0") {
            all_airports[stoi(route.source)].id = route.source;
          } else if (all_airports[stoi(route.dest)].id == "0") {
            all_airports[stoi(route.dest)].id = route.dest;
          }
        }
    }
    for (auto airport : all_airports) {
      if (airport.id != "0") {
        vertices_.push_back(airport.id);
      }
    }
}

void Graph::addEdge(Edge route) {    // add edge and set weight based on the distance
    double lat1 = all_airports[stoi(route.source)].latitude;
    //cout << "get s.la" << endl;
    double long1 = all_airports[stoi(route.source)].longitude;
    //cout << "get s.lo" << endl;
    double lat2 = all_airports[stoi(route.dest)].latitude;
    //cout << "get d.la" << endl;
    double long2 = all_airports[stoi(route.dest)].longitude;
    //cout << "get d.lo" << endl;
    route.weight = calDistance(lat1, lat2, long1, long2);
    adjList[route.source].push_back(pair<string, double>(route.source, route.weight));
}

double Graph::calDistance(double lat1, double lat2, double long1, double long2) {
    double dlat = ((M_PI) / 180 * lat2) - ((M_PI) / 180 * lat1);
    double dlong = ((M_PI) / 180 * long2) - ((M_PI) / 180 * long1);
    double result = pow(sin(dlat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(dlong / 2), 2);
    result = 2 * asin(sqrt(result));
    result *= 6371.0;
    return result;
}

vector<string> Graph::getVertices() {
    return vertices_;
}

vector<string> Graph::getShortestPathWeighted(const string &source, const string &dest) {
  // initialize
  unordered_map<string, double> d; // distance
  unordered_map<string, string> p; // previous
  for (auto &v : vertices_) {
    d[v] = numeric_limits<double>::infinity(); // set distance to +infinity
    p[v] = "";                                 // empty string means null
  }
  d[source] = 0; // set distance to source to 0

  // min distance priority queue, defined by d[v]
  priority_queue<pair<string, double>, vector<pair<string, double>>, greater<pair<string, double>>> Q;

  // build heap
  for (auto &v : vertices_) {
    Q.push(pair<string, double>(v, d[v]));
  }

  // labeled set
  set<string> T;

  // repeat n times, n is the number of vertices
  for (int i = 0; i < vertices_.size(); i++) {
    // remove min
    string u = Q.top().first;
    Q.pop();

    // add u to T
    T.insert(u);

    // for each neighbor v of u not in T
    for (auto &v : adjList[u]) {
      if (T.find(v.first) != T.end()) continue;

      // if cost(u, v) + d[u] < d[v]
      if (v.second + d[u] < d[v.first]) {
        // update d[v] to cost(u, v) + d[u]
        d[v.first] = v.second + d[u];
        // update p[v]
        p[v.first] = u;
      }
    }
  }

  // build shortest path
  vector<string> path;
  string u = dest;
  while (u != "") {
    path.push_back(u);
    u = p[u];
  }
  reverse(path.begin(), path.end());
  return path;
}

vector<string> Graph::getShortestPathUnweighted(const string &source, const string &dest) {
  vector<string> path;
  unordered_map<string, bool> visited;
  unordered_map<string, string> prev;
  for (auto &v : vertices_) {
    visited[v] = false;
  }

  queue<string> q;
  visited[source] = true;
  q.push(source);
  
  while (!q.empty()) {
    string cur = q.front();
    q.pop();
    
    for (auto adjacent : adjList[cur]) {
      string adj = adjacent.first;

      if (adj == dest) {
        prev[adj] = cur;
        string airport = dest;
        while (airport != "") {
          path.push_back(airport);
          airport = prev[airport];
        }
        reverse(path.begin(), path.end());
        return path;
      }

      if (!visited[adj]) {
        visited[adj] = true;
        prev[adj] = cur;
        q.push(adj);
      }
    }
  }
  return path;
}

void Graph::addVertex(const string &vertex) {
  vertices_.push_back(vertex);
}

void Graph::addEdge(const string &source, const string &dest, double distance) {
  adjList[source].push_back(pair<string, double>(dest, distance));
  adjList[dest].push_back(pair<string, double>(source, distance));
}