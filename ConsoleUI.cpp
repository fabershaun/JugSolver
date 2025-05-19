#include "ConsoleUI.h"
#include "JugSolver.h"
#include "Timer.h"
#include <iostream>

using namespace std;

void ConsoleUI::run()
{
	int smallJug, largeJug, goal;

	cin >> largeJug;
	cin >> smallJug;
	cin >> goal;

	JugSolver solver(smallJug, largeJug, goal);
	Timer timer;

	timer.start();
	if (!solver.solve())
		cout << "No solution." << endl;
	timer.stop();

	cout << "Execution time: " << timer.elapsedMilliseconds() << " ms" << endl;
}
