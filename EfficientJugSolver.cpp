#include "EfficientJugSolver.h"
#include <algorithm>

bool EfficientJugSolver::solve()
{
	queue<JugState> q;
	unordered_set<JugState, JugStateHasher> visited;

	q.push(startState);
	visited.insert(startState);

	while (!q.empty())
	{
		JugState current = q.front();
		q.pop();

		// Check if we have reached the goal state
		if (current == goalState)
		{
			JugAction::reconstructPath(startState, goalState, parentMap, moveMap);
			return true;
		}

		// Generate neighbors of the current state
		vector<JugState> neighbors = generateNeighbors(current);

		for (const JugState& neighbor : neighbors)
		{
			// If the neighbor has not been visited yet
			if (visited.find(neighbor) == visited.end())
			{
				visited.insert(neighbor);
				parentMap[neighbor] = current;
				moveMap[neighbor] = JugAction::identifyAction(current, neighbor);
				q.push(neighbor);
			}
		}
	}

	return false;
}

vector<JugState> EfficientJugSolver::generateNeighbors(const JugState& state)
{
	vector<JugState> neighbors;

	int s = state.getSmallJug();
	int l = state.getLargeJug();

	// Fill small jug if it's not full
	if (s < smallJugCap)	
		neighbors.emplace_back(smallJugCap, l);

	// Fill large jug if it's not full
	if (l < largeJugCap)
		neighbors.emplace_back(s, largeJugCap);

	// Empty small jug if it's not empty
	if (s > 0)
		neighbors.emplace_back(0, l);

	// Empty large jug if it's not empty
	if (l > 0)
		neighbors.emplace_back(s, 0);

	// Transfer from small to large if large jug is not full
	if (s > 0 && l < largeJugCap)
	{
		int transfer = min(s, largeJugCap - l);
		neighbors.emplace_back(s - transfer, l + transfer);
	}

	// Transfer from large to small if small jug is not full
	if (l > 0 && s < smallJugCap)
	{
		int transfer = min(l, smallJugCap - s);
		neighbors.emplace_back(s + transfer, l - transfer);
	}

	std::sort(neighbors.begin(), neighbors.end(), JugState::compareJugStates);
	return neighbors;
}
