#pragma once

#include <string>
#include <iostream>

using namespace std;


 // JugState class - represents a single state in the Water Jug Problem.
 // Support equality comparison for use in maps.
class JugState
{

private:
	int smallJug;
	int largeJug;

public:
	JugState(int small = 0, int large = 0) : smallJug(small), largeJug(large) {}

	int getSmallJug() const { return smallJug; }
	int getLargeJug() const { return largeJug; }

	bool operator==(const JugState& other) const
	{
		return smallJug == other.getSmallJug() && largeJug == other.getLargeJug();
	}

	bool operator!=(const JugState& other) const
	{
		return smallJug != other.getSmallJug() || largeJug != other.getLargeJug();
	}

	static bool compareJugStates(const JugState& a, const JugState& b);
};


struct JugStateHasher {
	std::size_t operator()(const JugState& state) const;
};