#pragma once

#include <unordered_map>
#include <vector>
#include "JugState.h"

using namespace std;

 // Graph class - represents the full state graph for the Water Jug Problem.
 // Build the complete graph for all possible states.
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

public:
	Graph(int smallJugCap, int largeJugCap) : smallJugMaxCapacity(smallJugCap), largeJugMaxCapacity(largeJugCap) {}

	const vector<JugState>& getAdjList(const JugState& state) { return adjList[state]; }
	
	void buildGraph();	
};

