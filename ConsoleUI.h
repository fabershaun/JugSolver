#pragma once

#include <iostream>
#include "Timer.h"
#include "JugSolver.h"
#include "EfficientJugSolver.h"

// ConsoleUI class - provides a user interface for the Water Jug Problem solver
class ConsoleUI
{
private:
	int largeJug;
	int smallJug;
	int goal;
	int implementationType;
	int runTime;

	void getInput();
	void validateInput() const;
	void solveProblem();

public:
	void run();
};

