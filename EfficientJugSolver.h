#pragma once

#include "JugState.h"
#include "JugAction.h"
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <vector>
#include <string>

using namespace std;

// EfficientJugSolver class - solves the Water Jug Problem using BFS with an efficient state representation
class EfficientJugSolver
{
private:
	JugState startState;
	JugState goalState;

	int smallJugCap;
	int largeJugCap;

	unordered_map<JugState, JugState, JugStateHasher> parentMap;
	unordered_map<JugState, string, JugStateHasher> moveMap;

public:
	EfficientJugSolver(int s, int l, int w) : startState(0, 0), goalState(0, w), smallJugCap(s), largeJugCap(l) {}

	bool solve();
	vector <JugState> generateNeighbors(const JugState& state);
};