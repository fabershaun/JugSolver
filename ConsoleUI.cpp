#include "ConsoleUI.h"
#include "JugSolver.h"
#include "Timer.h"
#include <iostream>

using namespace std;

void ConsoleUI::run()
{
	int smallJug, largeJug, goal;

	cout << "Enter small jug capacity: ";
	cin >> smallJug;

	cout << "Enter large jug capacity: ";
	cin >> largeJug;

	cout << "Enter goal amount: ";
	cin >> goal;

	JugSolver solver(smallJug, largeJug, goal);
	Timer timer;

	timer.start();
	if (!solver.solve())
		cout << "No solution." << endl;
	timer.stop();

	cout << "Execution time: " << timer.elapsedMilliseconds() << " ms" << endl;
}
