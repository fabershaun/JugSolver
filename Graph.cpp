#include "Graph.h"


// Adding all the posibile neighbors to a current state
vector<JugState> Graph::generateNeighbors(const JugState& state)
{
    vector<JugState> neighbors;

    int s = state.getSmallJug();
    int l = state.getLargeJug();

    // Add neighbor: fill the small jug
    if (s < smallJugMaxCapacity)
        neighbors.emplace_back(smallJugMaxCapacity, l);
           
    // Add neighbor: fill the large jug
    if (l < largeJugMaxCapacity)
        neighbors.emplace_back(s, largeJugMaxCapacity);

    // Add neighbor: empty Small jug
    if (s > 0)
        neighbors.emplace_back(0, l);

    // Add neighbor: empty large jug
    if (l > 0)
        neighbors.emplace_back(s, 0);

    // Add neighbor: transferring water from small to large 
    if (s > 0 && l < largeJugMaxCapacity)
    {
        int spareSpaceInL = largeJugMaxCapacity - l;
        int transfer = min(s, spareSpaceInL);
        neighbors.emplace_back(s - transfer, l + transfer);
    }

    // Add neighbor: transferring water from large to small 
    if (l > 0 && s < smallJugMaxCapacity)
    {
        int spareSpaceInS = smallJugMaxCapacity - s;
        int transfer = min(l, spareSpaceInS);
        neighbors.emplace_back(s + transfer, l - transfer);
    }

    std::sort(neighbors.begin(), neighbors.end(), compareJugStates);
    return neighbors;
}

bool Graph::compareJugStates(const JugState& a, const JugState& b)
{
    if (a.getSmallJug() == b.getSmallJug())         // If the small jugs are equal, we'll compare by the large jugs
        return a.getLargeJug() < b.getLargeJug();

    return a.getSmallJug() < b.getSmallJug();
}



// Build the full state graph:
// 1. Loop over all (small, large) states.
// 2. For each state, generate valid neighbors.
// 3. Add edges from state to each neighbor.
void Graph::buildGraph() 
{
    for (int s = 0; s <= smallJugMaxCapacity; ++s)
    {
        for (int l = 0; l <= largeJugMaxCapacity; ++l) 
        {
            JugState currentState(s, l);
            vector<JugState> neighbors = generateNeighbors(currentState); // Adding all the posibile neighbors to a current state
            for (const JugState& neighbor : neighbors)
            {
                addEdge(currentState, neighbor);                          // Adding all the edges between 'currentState' to his neighbors
            }
        }
    }
}