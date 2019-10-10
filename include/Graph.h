//
// Created by tbhat on 09-10-2019.
//

#ifndef UNTITLED_GRAPH_H
#define UNTITLED_GRAPH_H

#include <vector>
#include <map>

// Simplifying unsigned int
typedef unsigned int uint;
// An edge is a mapping from destination node to cost
typedef std::map<uint, uint> Edge;

class Graph {
private:
    /**
     * A vector of Edge type entries.
     * nodes[n-1]: Refers to an Edge map for node with the name 'n'
     *             It returns all the outgoing edges from node 'n'
     * nodes[n-1][e]: Returns the cost of a specific edge from node 'n'
     *                'e' is the name of the destination node
     */
    std::vector<Edge> nodes;
    /**
     * Checks if there is an edge from source node to destination node.
     * @param src Name of source node
     * @param dst Name of destination node
     * @return True if an edge exists, otherwise false
     */
    uint8_t edgeExists(uint src, uint dst) const;
    /**
     * Checks if a given node exists in the graph
     * @param n Name of the node
     * @return True if the node exists, otherwise fasle
     */
    inline bool nodeExists(uint n) const {
        // The name of the node must be in range 1 to size of nodes vector (both inclusive)
        return (0 < n && n <= nodes.size());
    }
public:
    /**
     * Constructor initializes the graph with given number of nodes and zero edges.
     * @param nodeCount Initial number of nodes in graph (default 0)
     */
    explicit Graph(uint nodeCount = 0);
    /**
     * Adds a node in the graph
     * @return The name of the node
     */
    uint addNode();
    /**
     * Adds an edge from source node to destination node, if it doesn't already exists.
     * @param src Name of source node
     * @param dst Name of destination node
     * @param cost Cost to traverse the edge (must be greater than 0)
     * @return False if the edge wasn't added to the graph, true otherwise
     */
    bool addEdge(uint src, uint dst, uint cost);
    /**
     * Returns names of nodes for which there exists an edge from source node
     * @param src Name of source node
     * @return Vector of edges from src
     */
    std::vector<uint> getEdges(uint src) const;
    /**
     * @param src Source node
     * @param dst Destination node
     * @return Cost of edge from src to dst, 0 if no edge exists
     */
    uint getCost(uint src, uint dst) const;
    /**
     * Prints the graph in adjacency-matrix representation
     * The rows represent source node while the column represent destination node
     * The value at (r,c) is the cost of travelling from node r to node c
     * A cost of 0 indicates "no edge" between nodes
     */
    void print() const;
};

struct Path {
    std::vector<uint> nodes;
    uint cost;
};

#endif //UNTITLED_GRAPH_H
