#pragma once
#include<chrono>

class Timer {
	const char* Name;
	std::chrono::time_point<std::chrono::steady_clock, std::chrono::microseconds> p_StartTimePoint;
public:
	Timer(const char* Name);
	~Timer();
private:
	std::chrono::time_point<std::chrono::steady_clock, std::chrono::microseconds> CurrentTimePoint();

	long long TimePointCount(std::chrono::time_point<std::chrono::steady_clock, std::chrono::microseconds>& timePoint);

	void WriteFile(long long& duration_micro);

};
