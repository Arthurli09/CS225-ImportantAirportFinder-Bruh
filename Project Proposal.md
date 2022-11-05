# Project Proposal

## Leading Question

What is the most important airport in a specific country?

Our goal: To answer the above question, we will use the data  from openflights.org to generate a graph. Then, we will design an algorithm to calculate the betweenness centrality for each airport in the country, and use Dijkstra’s algorithm (that computes the shortest path) to help obtain the betweenness centrality. Finally, we will compare all the betweenness centrality between the airports in that country to find the most important airport (the country will be designated by user input).

## Dataset Acquisition

Detailed information included below👇
## Data Format
.CSV. The dataset provided by OpenFlights contains 14110 nodes(airports), and 21317 edges(flights), as of June, 2014.  Depending on the user’s input, we will make a subset out of the dataset that only contains airports in that designated country. 

## Data Correction
When reading the input line by line, we will first parse the data of each line by “,” and put it into a vector. After that, we will check whether the elements in the vector are in a reasonable range. eg: check the latitude and longitude are not out of bound,  the length of the IATA code must be between 2-3, and that of ICAO code must be between 3-4, etc. If every element in the vector passed the test, we pushed the vector into our storage, if not, we will use “continue” to pass to the next line.
## Data Storage
We will use the graph to store the data and some STL structures may be utilized to help implement our algorithms, such as queue, vector. The total storage cost is O(n).
## Algorithm 
We will design an algorithm to calculate the betweenness centrality for each airport in the country, and use Dijkstra’s algorithm (that computes the shortest path) to help obtain the betweenness centrality. Finally, we will compare all the betweenness centrality between the airports in that country to find the most important airport (the country will be designated by user input).
The expected input will be a vector of airports (which is the output of another function (which takes in the .csv file and the user inputted country name and processes the .csv file) before being imputed to the graph algorithm), then the expected output is a string that represents the name of the most important airport. The estimated runtime is O(m+nlog(n)).


## Timeline
Sort, filter, and process the input data — 1 week

Finish every graph related algorithm — 2 weeks

Test and debug — 1 week
