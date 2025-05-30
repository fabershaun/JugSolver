#include "JugState.h"

std::size_t JugStateHasher::operator()(const JugState& state) const
{
    std::size_t h1 = std::hash<int>()(state.getSmallJug());
    std::size_t h2 = std::hash<int>()(state.getLargeJug());
    return h1 ^ (h2 << 1);                                      // combine hashes
}

bool JugState::compareJugStates(const JugState& a, const JugState& b)
{
    if (a.getSmallJug() == b.getSmallJug())         // If the small jugs are equal, we'll compare by the large jugs
        return a.getLargeJug() < b.getLargeJug();

    return a.getSmallJug() < b.getSmallJug();
}
