#include <iostream>
#include <iomanip>
#include "Graph.h"

Graph::Graph(uint nodeCount) : nodes(nodeCount, Edge()) {}

uint8_t Graph::edgeExists(uint src, uint dst) const {
    if (nodeExists(src) && nodeExists(dst))
        /* Accessing node 'src' at index 'src-1'
         * For node src, checking if any of the edges go to dest
         * Returns 1 if edgeExists, 0 otherwise
         */
        return (nodes[src-1].find(dst) != nodes[src-1].end());
    // The given node(s) don't exist
    return 2;
}

uint Graph::addNode() {
    // Name set as last node + 1; to preserve sequence
    nodes.emplace_back();
    return nodes.size();
}

bool Graph::addEdge(uint src, uint dst, uint cost) {
    // If edge doesn't already exists and cost is greater than 0
    if(!edgeExists(src, dst) && cost > 0) {
        // Adding the new edge
        nodes[src-1][dst] = cost;
        return true;
    } else return false; // Failure
}

std::vector<uint> Graph::getEdges(uint src) const {
    // Vector containing destination names of edges
    std::vector<uint> edges;
    if (nodeExists(src))
        // Iterating all edges in node 'src'
        for (auto &e : nodes[src-1])
            // Add destination name (map key) to vector
            edges.push_back(e.first);
    return edges;
}

uint Graph::getCost(uint src, uint dst) const {
    try {
        if (!nodeExists(src) || !nodeExists(dst))
            throw std::runtime_error("Node doesn't exist");
        // Throws out_of_range exception if edge doesn't exist
        uint cost = nodes[src - 1].at(dst);
        return cost;
    } catch (std::exception& e) { return 0; }
}

void Graph::print() const {
    using namespace std;
    // First row
    cout << "   ";
    for(int i = 1; i <= nodes.size(); i++)
        // Destination node numbering
        cout << setw(2) << i << " ";
    cout << endl;
    // Consequent rows
    for (int i = 0; i < nodes.size(); i++) {
        // First column; Source node numbering
        cout << setw(2) << i+1 << " ";
        // Cost of edge from node i to j
        for (int j = 1; j <= nodes.size(); j++)
            cout << setw(2) << getCost(i+1, j) << " ";
        cout << endl;
    }
}
