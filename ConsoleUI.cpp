#include "ConsoleUI.h"

using namespace std;

void ConsoleUI::getInput()
{
	cin >> largeJug >> smallJug >> goal >> implementationType >> runTime;
}

void ConsoleUI::validateInput() const
{
	if (largeJug <= 0 || smallJug <= 0 || goal < 0 ||
        largeJug <= smallJug || goal > largeJug ||
        (implementationType != 1 && implementationType != 2) ||	(runTime != 0 && runTime != 1))
	{
		cout << "invalid input" << endl;
		exit(1);
	}
}

void ConsoleUI::solveProblem()
{
    bool success = false;
    Timer timer;

    if (implementationType == 1)
    {
        JugSolver solver(smallJug, largeJug, goal);
        if (runTime) 
            timer.start();

        success = solver.solve();
        if (runTime)
        {
            timer.stop();
            cout << "Execution time: " << timer.elapsedMilliseconds() << " ms" << endl;
        }
    }
    else if (implementationType == 2)
    {
        EfficientJugSolver solver(smallJug, largeJug, goal);
        if (runTime)
            timer.start();

        success = solver.solve();
        if (runTime)
        {
            timer.stop();
            cout << "Execution time: " << timer.elapsedMilliseconds() << " ms" << endl;
        }
    }

    if (!success)
        cout << "No solution." << endl;
}

void ConsoleUI::run()
{
    getInput();
    validateInput();
    solveProblem();
}
