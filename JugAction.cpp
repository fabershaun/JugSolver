#include "JugAction.h"
#include <algorithm>

void JugAction::reconstructPath(const JugState& startState, const JugState& goal, const unordered_map<JugState, JugState, JugStateHasher>& parentMap, const unordered_map<JugState, std::string, JugStateHasher>& moveMap)
{
    vector<JugState> path;
    JugState current = goal;

    // Reconstruct path - from the end to the beginning
    while (current != startState)
    {
        path.push_back(current);
        current = parentMap.at(current);
    }

    path.push_back(startState);
    reverse(path.begin(), path.end());

    printReconstructPath(path, moveMap);
}

string JugAction::identifyAction(const JugState& before, const JugState& after)
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

    else if (l2 > l1 && s2 < s1)
        return "Transfer from small jug to large jug";

    else if (l2 < l1 && s2 > s1)
        return "Transfer from large jug to small jug";

    else
        return "Unknown action";
}

void JugAction::printReconstructPath(const vector<JugState>& path, const unordered_map<JugState, string, JugStateHasher>& moveMap)
{
    cout << "Number of operations: " << path.size() - 1 << endl;
    cout << "Operations:" << endl;

    for (int i = 1; i < path.size(); i++)
        cout << i << ". " << moveMap.at(path[i]) << endl;
}
