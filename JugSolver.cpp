#include "JugSolver.h"


string JugSolver::identifyAction(const JugState& before, const JugState& after)
{
    int s1 = before.getSmallJug(), l1 = before.getLargeJug();
    int s2 = after.getSmallJug(), l2 = after.getLargeJug();

    // Fill - one jug is bigger, the other is the same
    // Empty - one jug is zero, the other is the same
    // Transfer - one jug is bigger, the other is smaller

    if (s2 > s1 && l2 == l1)
        return "Fill small jug";

    else if (l2 > l1 && s2 == s1)
        return "Fill large jug";

    else if (s1 > 0 && s2 == 0 && l2 == l1)
        return "Empty small jug";

    else if (l1 > 0 && l2 == 0 && s2 == s1)
        return "Empty large jug";

    else if(l2 > l1 && s2 < s1)
        return "Transfer from small jug to large jug";

    else if (l2 < l1 && s2 > s1)
        return "Transfer from large jug to small jug";
    
    else
        return "Unknown action";
}

void JugSolver::reconstructPath(const JugState& goal)
{
    vector<JugState> path;
    JugState current = goal;

    // Reconstruct path - from the end to the beginning
    while (current != startState)
    {
        path.push_back(current);
        current = parentMap[current];
    }

    path.push_back(startState);
    reverse(path.begin(), path.end());

    printReconstructPath(path);
}


void JugSolver::printReconstructPath(vector<JugState> path)
{
    cout << "Number of operations: " << path.size() - 1 << endl;
    cout << "States:" << endl;

    for (int i = 1; i < path.size(); i++)
        cout << i << "." << moveMap[path[i]] << endl;
}


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
            reconstructPath(current);
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
                moveMap[neighbor] = identifyAction(current, neighbor);
                q.push(neighbor);
            }
        }
    }

    // If we didn't find a solution
    return false;
}
