#pragma once

#include <iostream>
#include <unordered_set>
#include <queue>
#include <algorithm>
#include "Graph.h"
#include "JugAction.h"

using namespace std;

// JugSolver class – solves the Water Jug Problem using BFS.
// Solve the problem using BFS.
class JugSolver
{


private:

    JugState startState;
    JugState goalState;

    Graph graph;

    unordered_map<JugState, JugState, JugStateHasher> parentMap;
    unordered_map<JugState, string, JugStateHasher> moveMap;

public:
    JugSolver(int s, int l, int w) : startState(0, 0), goalState(0, w), graph(s, l) 
    {
        graph.buildGraph();
    }

    bool solve();
};