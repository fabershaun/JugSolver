#pragma once

#include "JugState.h"
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// JugAction class - identifies the action taken between two jug states
class JugAction
{
private:
    static void printReconstructPath(const vector<JugState>& path, const unordered_map<JugState, string, JugStateHasher>& moveMap);

public:
    static void reconstructPath(
        const JugState& start,
        const JugState& goal,
        const unordered_map<JugState, JugState, JugStateHasher>& parentMap,
        const unordered_map<JugState, std::string, JugStateHasher>& moveMap
    );
	static string identifyAction(const JugState& before, const JugState& after);

};

