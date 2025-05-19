#pragma once

#include <chrono>

class Timer
{
private:
	std::chrono::high_resolution_clock::time_point start_time;
	std::chrono::high_resolution_clock::time_point end_time;

public:
	void start() { start_time = std::chrono::high_resolution_clock::now(); }
	void stop() { end_time = std::chrono::high_resolution_clock::now(); }
	double elapsedMilliseconds() {	return std::chrono::duration<double, std::milli>(end_time - start_time).count(); }
	double elapsedSeconds() { return std::chrono::duration<double>(end_time - start_time).count(); }
};

