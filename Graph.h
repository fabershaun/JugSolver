#pragma once

#include <unordered_map>
#include <vector>
#include <algorithm>
#include "JugState.h"

using namespace std;

/*
 * Graph class - represents the full state graph for the Water Jug Problem.
 *
 * Responsibilities:
 * - Represent each jug state (small, large) as a graph node.
 * - Define edges between states via valid operations (fill, empty, transfer).
 * - Build the complete graph for all possible states.
 * - Provide access to neighbors of a given state (lexicographically sorted).
 *
 * Used in:
 * - BFS search to find the shortest sequence of operations from (0,0) to (0,W).
 */

class Graph
{

private:
	int smallJugMaxCapacity;	
	int largeJugMaxCapacity;

	// Adjacency list: maps each jug state to its valid neighbors
	unordered_map<JugState, vector<JugState>, JugStateHasher> adjList;

	// Adds a directed edge from one state to another
	void addEdge(const JugState& from, const JugState& to) 
	{
		adjList[from].push_back(to);
	}

	// Generates all valid one-move neighbor states from the current state
	vector<JugState> generateNeighbors(const JugState& state);

	static bool compareJugStates(const JugState& a, const JugState& b);

public:
	Graph(int smallJugCap, int largeJugCap) : smallJugMaxCapacity(smallJugCap), largeJugMaxCapacity(largeJugCap) {}

	const vector<JugState>& getAdjList(const JugState& state) { return adjList[state]; }
	
	void buildGraph();	
};

