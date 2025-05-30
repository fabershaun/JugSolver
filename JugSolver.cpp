#include "JugSolver.h"

bool JugSolver::solve()
{
    queue<JugState> q;
    unordered_set<JugState, JugStateHasher> visited;

    q.push(startState);
    visited.insert(startState);

    while (!q.empty())
    {
        JugState current = q.front();
        q.pop();

        // Check if we reached the goal amount
        if (current == goalState)
        {
            JugAction::reconstructPath(startState, goalState, parentMap, moveMap);
            return true;
        }

        // Otherwise: we will check his neighbors
        for (const JugState& neighbor : graph.getAdjList(current))
        {
            // If we didn't already check 'neighbor' -> we will contiue the search with him
            if (visited.find(neighbor) == visited.end())
            {
                visited.insert(neighbor);
                parentMap[neighbor] = current;
                moveMap[neighbor] = JugAction::identifyAction(current, neighbor);
                q.push(neighbor);
            }
        }
    }

    // If we didn't find a solution
    return false;
}
