#pragma once

#include <iostream>
#include <unordered_set>
#include <queue>
#include <algorithm>
#include "Graph.h"

using namespace std;

/*
 * JugSolver class – solves the Water Jug Problem using BFS.
 *
 * Responsibilities:
 * - Solve the problem using BFS.
 * - Track the path from start to goal using a parent map.
 * - Record the actions taken between states using a move map.
 *
 */

class JugSolver
{
private:

    JugState startState;
    JugState goalState;

    Graph graph;

    unordered_map<JugState, JugState, JugStateHasher> parentMap;
    unordered_map<JugState, string, JugStateHasher> moveMap;

    string identifyAction(const JugState& from, const JugState& to);
    void reconstructPath(const JugState& goalState);
    void printReconstructPath(vector<JugState> path);
public:
    JugSolver(int s, int l, int w) : startState(0, 0), goalState(0, w), graph(s, l) {}

    bool solve();
};